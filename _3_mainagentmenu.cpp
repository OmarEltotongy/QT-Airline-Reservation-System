#include "_3_mainagentmenu.h"
#include "ui__3_mainagentmenu.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

mainAgentMenu::mainAgentMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainAgentMenu)
{
    ui->setupUi(this);
    setWindowTitle("EltoWing System - Agent Dashboard");

    // Initialize tables
    QStringList flightHeaders = {"Flight #", "Origin", "Destination", "Departure", "Price", "Available Seats"};
    ui->flightsTable->setColumnCount(flightHeaders.size());
    ui->flightsTable->setHorizontalHeaderLabels(flightHeaders);
    ui->flightsTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    QStringList reservationHeaders = {"Reservation ID", "Flight #", "Passenger", "Seat", "Status", "Route"};
    ui->modifyTable->setColumnCount(reservationHeaders.size());
    ui->modifyTable->setHorizontalHeaderLabels(reservationHeaders);
    ui->cancelTable->setColumnCount(reservationHeaders.size());
    ui->cancelTable->setHorizontalHeaderLabels(reservationHeaders);

    // Connect signals
    connect(ui->flightsTable, &QTableWidget::itemDoubleClicked, this, &mainAgentMenu::onFlightDoubleClicked);
    ui->modifyButton->setEnabled(false);
    ui->cancelButton->setEnabled(false);
}

mainAgentMenu::~mainAgentMenu()
{
    delete ui;
}

void mainAgentMenu::on_searchButton_clicked()
{
    QString origin = ui->originInput->text().trimmed();
    QString destination = ui->destInput->text().trimmed();
    QString date = ui->dateInput->text().trimmed();

    if (origin.isEmpty() || destination.isEmpty() || date.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill in all search fields.");
        return;
    }

    json flightsData = readFromJson("../../data/flights.json");
    if (flightsData.is_null()) {
        QMessageBox::critical(this, "Error", "Could not read flights data.");
        return;
    }

    json matchingFlights = json::array();
    for (const auto &flight : flightsData["flights"]) {
        if ((flight["origin"] == origin.toStdString()) &&
            (flight["destination"] == destination.toStdString()) &&
            (flight["departureTime"].get<std::string>().find(date.toStdString()) != std::string::npos)) {
            matchingFlights.push_back(flight);
        }
    }

    displayFlights(matchingFlights);
}

void mainAgentMenu::displayFlights(const json &flights)
{
    ui->flightsTable->setRowCount(0);

    if (flights.empty()) {
        QMessageBox::information(this, "Information", "No flights found matching your criteria.");
        return;
    }

    for (const auto &flight : flights) {
        int row = ui->flightsTable->rowCount();
        ui->flightsTable->insertRow(row);

        ui->flightsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(flight["flightNumber"])));
        ui->flightsTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(flight["origin"])));
        ui->flightsTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(flight["destination"])));
        ui->flightsTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(flight["departureTime"])));
        ui->flightsTable->setItem(row, 4, new QTableWidgetItem(QString::number(flight["price"].get<double>(), 'f', 2)));
        ui->flightsTable->setItem(row, 5, new QTableWidgetItem(QString::number(flight["availableSeats"].get<int>())));
    }

    ui->flightsTable->resizeColumnsToContents();
}

void mainAgentMenu::onFlightDoubleClicked(QTableWidgetItem *item)
{
    QString flightNumber = ui->flightsTable->item(item->row(), 0)->text();
    ui->flightNumInput->setText(flightNumber);
    ui->tabWidget->setCurrentIndex(1); // Switch to booking tab
}

void mainAgentMenu::on_bookButton_clicked()
{
    QString flightNumber = ui->flightNumInput->text().trimmed();
    QString seatNumber = ui->seatInput->text().trimmed().toUpper();
    QString passengerUsername = ui->passengerInput->text().trimmed();

    if (flightNumber.isEmpty() || seatNumber.isEmpty() || passengerUsername.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill in all required fields.");
        return;
    }

    // Check payment method
    QString paymentMethod;
    if (ui->walletRadio->isChecked()) {
        paymentMethod = "Wallet";
    } else if (ui->paypalRadio->isChecked()) {
        paymentMethod = "PayPal";
    } else if (ui->creditRadio->isChecked()) {
        paymentMethod = "CreditCard";
    } else {
        QMessageBox::warning(this, "Warning", "Please select a payment method.");
        return;
    }

    // Read data files
    json flights = readFromJson("../../data/flights.json");
    json users = readFromJson("../../data/users.json");
    json reservations = readFromJson("../../data/reservation.json");

    if (flights.is_null() || users.is_null() || reservations.is_null()) {
        QMessageBox::critical(this, "Error", "Could not read required data files.");
        return;
    }

    // Find passenger
    json* passenger = nullptr;
    for (auto& user : users["users"]) {
        if (user["username"] == passengerUsername.toStdString() && user["role"] == "PASSENGER") {
            passenger = &user;
            break;
        }
    }

    if (!passenger) {
        QMessageBox::warning(this, "Warning", "Passenger not found.");
        return;
    }

    // Find flight
    int flightIndex = -1;
    for (size_t i = 0; i < flights["flights"].size(); ++i) {
        if (flights["flights"][i]["flightNumber"] == flightNumber.toStdString()) {
            flightIndex = i;
            break;
        }
    }

    if (flightIndex == -1) {
        QMessageBox::warning(this, "Warning", "Flight not found.");
        return;
    }

    // Check seat availability
    if (!isSeatAvailable(flightNumber, seatNumber, reservations)) {
        QMessageBox::warning(this, "Warning", QString("Seat %1 is already taken on flight %2").arg(seatNumber).arg(flightNumber));
        return;
    }

    // Get flight details
    double price = flights["flights"][flightIndex]["price"];
    std::string origin = flights["flights"][flightIndex]["origin"];
    std::string destination = flights["flights"][flightIndex]["destination"];
    std::string departureTime = flights["flights"][flightIndex]["departureTime"];

    // Calculate discount based on loyalty points (10% per 100 points, max 50%)
    int loyaltyPoints = (*passenger)["loyaltyPoints"];
    double discount = 0.0;

    if (loyaltyPoints >= 100) {
        discount = std::min(0.50, 0.10 * (loyaltyPoints / 100)); // Max 50% discount
        int pointsToUse = (discount / 0.10) * 100; // Calculate points to deduct
        (*passenger)["loyaltyPoints"] = loyaltyPoints - pointsToUse;
    }

    double discountedPrice = price * (1 - discount);

    // Process payment with discounted price
    if (paymentMethod == "Wallet") {
        double walletBalance = (*passenger)["wallet"];
        if (walletBalance < discountedPrice) {
            QMessageBox::warning(this, "Warning", "Passenger has insufficient wallet balance.");
            return;
        }
        (*passenger)["wallet"] = walletBalance - discountedPrice;
    }

    // Award new loyalty points (1 point per $10 spent, rounded down)
    int pointsEarned = static_cast<int>(discountedPrice / 10);
    (*passenger)["loyaltyPoints"] = (*passenger)["loyaltyPoints"].get<int>() + pointsEarned;


    // Create reservation
    std::string reservationID = "R" + std::to_string(reservations["reservations"].size() + 1);
    json newReservation = {
        {"reservationID", reservationID},
        {"flightNumber", flightNumber.toStdString()},
        {"passengerID", (*passenger)["userID"]},
        {"seatNumber", seatNumber.toStdString()},
        {"status", "PENDING"},
        {"origin", origin},
        {"destination", destination},
        {"departureTime", departureTime}
    };

    // Update data
    reservations["reservations"].push_back(newReservation);
    flights["flights"][flightIndex]["availableSeats"] = flights["flights"][flightIndex]["availableSeats"].get<int>() - 1;

    // Write back to files
    if (!writeToJson("../../data/flights.json", flights) ||
        !writeToJson("../../data/users.json", users) ||
        !writeToJson("../../data/reservation.json", reservations)) {
        QMessageBox::critical(this, "Error", "Failed to save data.");
        return;
    }

    // Show confirmation
    showBookingConfirmation(QString::fromStdString(reservationID),
                            flightNumber,
                            QString::fromStdString(origin),
                            QString::fromStdString(destination),
                            seatNumber,
                            discountedPrice);

    // Clear fields
    ui->flightNumInput->clear();
    ui->seatInput->clear();
}

void mainAgentMenu::on_modifySearchButton_clicked()
{
    QString username = ui->modifyUserInput->text().trimmed();
    if (username.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a username.");
        return;
    }

    json reservations = readFromJson("../../data/reservation.json");
    json users = readFromJson("../../data/users.json");

    if (reservations.is_null() || users.is_null()) {
        QMessageBox::critical(this, "Error", "Could not read data files.");
        return;
    }

    // Find passenger ID
    QString passengerID;
    for (const auto& user : users["users"]) {
        if (user["username"] == username.toStdString()) {
            passengerID = QString::fromStdString(user["userID"]);
            break;
        }
    }

    if (passengerID.isEmpty()) {
        QMessageBox::warning(this, "Warning", "User not found.");
        return;
    }

    // Find reservations
    json passengerReservations = json::array();
    for (const auto& reservation : reservations["reservations"]) {
        if (reservation["passengerID"] == passengerID.toStdString()) {
            passengerReservations.push_back(reservation);
        }
    }

    displayReservations(passengerReservations, ui->modifyTable);
    ui->modifyButton->setEnabled(true);
    currentPassengerID = passengerID;
}

void mainAgentMenu::on_modifyButton_clicked()
{
    QList<QTableWidgetItem*> selected = ui->modifyTable->selectedItems();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a reservation to modify.");
        return;
    }

    QString reservationID = ui->modifyTable->item(selected.first()->row(), 0)->text();
    QString newSeat = ui->newSeatInput->text().trimmed().toUpper();

    if (newSeat.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a new seat number.");
        return;
    }

    json reservations = readFromJson("../../data/reservation.json");
    if (reservations.is_null()) {
        QMessageBox::critical(this, "Error", "Could not read reservations data.");
        return;
    }

    // Find reservation
    bool found = false;
    for (auto& reservation : reservations["reservations"]) {
        if (reservation["reservationID"] == reservationID.toStdString()) {
            found = true;

            // Check if seat is available
            if (!isSeatAvailable(QString::fromStdString(reservation["flightNumber"]), newSeat, reservations)) {
                QMessageBox::warning(this, "Warning", QString("Seat %1 is already taken").arg(newSeat));
                return;
            }

            reservation["seatNumber"] = newSeat.toStdString();
            break;
        }
    }

    if (!found) {
        QMessageBox::warning(this, "Warning", "Reservation not found.");
        return;
    }

    if (!writeToJson("../../data/reservation.json", reservations)) {
        QMessageBox::critical(this, "Error", "Failed to save data.");
        return;
    }

    QMessageBox::information(this, "Success", "Seat modified successfully.");
    on_modifySearchButton_clicked(); // Refresh the list
}

void mainAgentMenu::on_cancelSearchButton_clicked()
{
    QString username = ui->cancelUserInput->text().trimmed();
    if (username.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a username.");
        return;
    }

    json reservations = readFromJson("../../data/reservation.json");
    json users = readFromJson("../../data/users.json");

    if (reservations.is_null() || users.is_null()) {
        QMessageBox::critical(this, "Error", "Could not read data files.");
        return;
    }

    // Find passenger ID
    QString passengerID;
    for (const auto& user : users["users"]) {
        if (user["username"] == username.toStdString()) {
            passengerID = QString::fromStdString(user["userID"]);
            break;
        }
    }

    if (passengerID.isEmpty()) {
        QMessageBox::warning(this, "Warning", "User not found.");
        return;
    }

    // Find reservations
    json passengerReservations = json::array();
    for (const auto& reservation : reservations["reservations"]) {
        if (reservation["passengerID"] == passengerID.toStdString()) {
            passengerReservations.push_back(reservation);
        }
    }

    displayReservations(passengerReservations, ui->cancelTable);
    ui->cancelButton->setEnabled(true);
    currentPassengerID = passengerID;
}

void mainAgentMenu::on_cancelButton_clicked()
{
    QList<QTableWidgetItem*> selected = ui->cancelTable->selectedItems();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a reservation to cancel.");
        return;
    }

    QString reservationID = ui->cancelTable->item(selected.first()->row(), 0)->text();

    json reservations = readFromJson("../../data/reservation.json");
    json flights = readFromJson("../../data/flights.json");

    if (reservations.is_null() || flights.is_null()) {
        QMessageBox::critical(this, "Error", "Could not read data files.");
        return;
    }

    // Find reservation
    bool found = false;
    QString flightNumber;
    for (auto& reservation : reservations["reservations"]) {
        if (reservation["reservationID"] == reservationID.toStdString()) {
            found = true;
            flightNumber = QString::fromStdString(reservation["flightNumber"]);

            // Update status to CANCELLED instead of removing
            reservation["status"] = "CANCELLED";
            break;
        }
    }

    if (!found) {
        QMessageBox::warning(this, "Warning", "Reservation not found.");
        return;
    }

    // Increment available seats on flight
    for (auto& flight : flights["flights"]) {
        if (flight["flightNumber"] == flightNumber.toStdString()) {
            flight["availableSeats"] = flight["availableSeats"].get<int>() + 1;
            break;
        }
    }

    if (!writeToJson("../../data/reservation.json", reservations) ||
        !writeToJson("../../data/flights.json", flights)) {
        QMessageBox::critical(this, "Error", "Failed to save data.");
        return;
    }

    QMessageBox::information(this, "Success", "Reservation cancelled successfully.");
    on_cancelSearchButton_clicked(); // Refresh the list
}

void mainAgentMenu::displayReservations(const json &reservations, QTableWidget *table)
{
    table->setRowCount(0);

    if (reservations.empty()) {
        QMessageBox::information(this, "Information", "No reservations found.");
        return;
    }

    json users = readFromJson("../../data/users.json");

    for (const auto &reservation : reservations) {
        int row = table->rowCount();
        table->insertRow(row);

        // Set different text color for cancelled reservations
        QColor textColor = (reservation["status"] == "CANCELLED") ? Qt::gray : Qt::black;

        QTableWidgetItem* idItem = new QTableWidgetItem(QString::fromStdString(reservation["reservationID"]));
        idItem->setForeground(textColor);
        table->setItem(row, 0, idItem);

        QTableWidgetItem* flightItem = new QTableWidgetItem(QString::fromStdString(reservation["flightNumber"]));
        flightItem->setForeground(textColor);
        table->setItem(row, 1, flightItem);

        // Find passenger name
        QString passengerName;
        for (const auto& user : users["users"]) {
            if (user["userID"] == reservation["passengerID"]) {
                passengerName = QString::fromStdString(user["username"]);
                break;
            }
        }
        QTableWidgetItem* passengerItem = new QTableWidgetItem(passengerName);
        passengerItem->setForeground(textColor);
        table->setItem(row, 2, passengerItem);

        QTableWidgetItem* seatItem = new QTableWidgetItem(QString::fromStdString(reservation["seatNumber"]));
        seatItem->setForeground(textColor);
        table->setItem(row, 3, seatItem);

        QTableWidgetItem* statusItem = new QTableWidgetItem(QString::fromStdString(reservation["status"]));
        statusItem->setForeground(textColor);
        table->setItem(row, 4, statusItem);

        QString route = QString::fromStdString(reservation["origin"]) + " → " +
                        QString::fromStdString(reservation["destination"]);
        QTableWidgetItem* routeItem = new QTableWidgetItem(route);
        routeItem->setForeground(textColor);
        table->setItem(row, 5, routeItem);
    }

    table->resizeColumnsToContents();
}

bool mainAgentMenu::isSeatAvailable(const QString &flightNumber, const QString &seatNumber, const json &reservations)
{
    for (const auto& reservation : reservations["reservations"]) {
        if (reservation["flightNumber"] == flightNumber.toStdString() &&
            QString::fromStdString(reservation["seatNumber"]).toUpper() == seatNumber.toUpper()) {
            return false;
        }
    }
    return true;
}

json mainAgentMenu::readFromJson(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        return json();
    }

    QTextStream in(&file);
    QString jsonStr = in.readAll();
    file.close();

    return json::parse(jsonStr.toStdString());
}

bool mainAgentMenu::writeToJson(const QString &filename, const json &data)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    QTextStream out(&file);
    out << QString::fromStdString(data.dump(4));
    file.close();

    return true;
}

void mainAgentMenu::showBookingConfirmation(const QString &reservationID,
                                            const QString &flightNumber,
                                            const QString &origin,
                                            const QString &destination,
                                            const QString &seatNumber,
                                            double price)
{
    QString message = QString(
                          "<h3>Booking Successful!</h3>"
                          "<p><b>Reservation ID:</b> %1</p>"
                          "<p><b>Flight:</b> %2 from %3 to %4</p>"
                          "<p><b>Seat:</b> %5</p>"
                          "<p><b>Total Cost:</b> $%6</p>"
                          ).arg(reservationID, flightNumber, origin, destination, seatNumber, QString::number(price, 'f', 2));

    QMessageBox::information(this, "Booking Confirmation", message);
}
