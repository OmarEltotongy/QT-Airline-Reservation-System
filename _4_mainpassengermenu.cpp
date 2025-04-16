#include "_4_mainpassengermenu.h"
#include "ui__4_mainpassengermenu.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>

mainPassengerMenu::mainPassengerMenu(QString &username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainPassengerMenu),
    currentUsername(username)
{
    ui->setupUi(this);
    setWindowTitle("EltoWing System - Passenger Dashboard");

    // Initialize UI elements
    ui->flightsTable->setColumnCount(5);
    ui->flightsTable->setHorizontalHeaderLabels({"Flight #", "Origin", "Destination", "Departure", "Price"});
    ui->flightsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->flightsTable->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->reservationsTable->setColumnCount(6);
    ui->reservationsTable->setHorizontalHeaderLabels({"Reservation ID", "Flight #", "Route", "Departure", "Seat", "Status"});
    ui->reservationsTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Connect signals
    connect(ui->backToSearchBtn, &QPushButton::clicked, this, &mainPassengerMenu::clearFlightResults);
    connect(ui->selectFlightBtn, &QPushButton::clicked, this, &mainPassengerMenu::selectFlight);
    connect(ui->flightsTable, &QTableWidget::itemDoubleClicked, this, &mainPassengerMenu::onFlightDoubleClicked);
}

mainPassengerMenu::~mainPassengerMenu()
{
    delete ui;
}

void mainPassengerMenu::on_searchFlightsBtn_clicked()
{
    QString origin = ui->searchOriginLineEdit->text().trimmed();
    QString destination = ui->searchDestinationLineEdit->text().trimmed();
    QString date = ui->searchDateLineEdit->text().trimmed();

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

void mainPassengerMenu::displayFlights(const json &flights)
{
    ui->flightsTable->setRowCount(0); // Clear previous results

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
    }

    ui->flightsTable->resizeColumnsToContents();
    ui->backToSearchBtn->setEnabled(true);
    ui->selectFlightBtn->setEnabled(true);
}

void mainPassengerMenu::clearFlightResults()
{
    ui->flightsTable->setRowCount(0);
    ui->backToSearchBtn->setEnabled(false);
    ui->selectFlightBtn->setEnabled(false);
}

void mainPassengerMenu::selectFlight()
{
    QList<QTableWidgetItem*> selected = ui->flightsTable->selectedItems();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a flight first.");
        return;
    }

    QString flightNumber = ui->flightsTable->item(selected.first()->row(), 0)->text();
    ui->bookFlightNumberLineEdit->setText(flightNumber);
    ui->passengerTabWidget->setCurrentIndex(1); // Switch to booking tab
}

void mainPassengerMenu::onFlightDoubleClicked(QTableWidgetItem *item)
{
    QString flightNumber = ui->flightsTable->item(item->row(), 0)->text();
    ui->bookFlightNumberLineEdit->setText(flightNumber);
    ui->passengerTabWidget->setCurrentIndex(1); // Switch to booking tab
}

void mainPassengerMenu::on_BookTheFlightBtn_clicked()
{
    QString flightNumber = ui->bookFlightNumberLineEdit->text().trimmed();
    QString seatNumber = ui->bookSeatNumberLineEdit->text().trimmed();

    if (flightNumber.isEmpty() || seatNumber.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill in all required fields.");
        return;
    }

    // Normalize seat number to uppercase for comparison
    QString normalizedSeat = seatNumber.toUpper();

    // Check which payment method is selected
    QString paymentMethod;
    if (ui->walletRadioButton->isChecked()) {
        paymentMethod = "Wallet";
    } else if (ui->paypalRadioButton->isChecked()) {
        paymentMethod = "PayPal";
    } else if (ui->creditcardRadioButton->isChecked()) {
        paymentMethod = "CreditCard";
    } else {
        QMessageBox::warning(this, "Warning", "Please select a payment method.");
        return;
    }

    // Read data from files
    json flights = readFromJson("../../data/flights.json");
    json users = readFromJson("../../data/users.json");
    json reservations = readFromJson("../../data/reservation.json");

    if (flights.is_null() || users.is_null() || reservations.is_null()) {
        QMessageBox::critical(this, "Error", "Could not read required data files.");
        return;
    }

    // Find the flight
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

    // Check available seats
    if (flights["flights"][flightIndex]["availableSeats"] <= 0) {
        QMessageBox::warning(this, "Warning", "No available seats on this flight.");
        return;
    }

    // Check if seat is already taken on this flight
    for (const auto& reservation : reservations["reservations"]) {
        if (reservation["flightNumber"] == flightNumber.toStdString() &&
            QString::fromStdString(reservation["seatNumber"]).toUpper() == normalizedSeat) {
            QMessageBox::warning(this, "Seat Taken",
                                 QString("Seat %1 is already taken on flight %2. Please choose another seat.")
                                     .arg(seatNumber).arg(flightNumber));
            return;
        }
    }

    // Get flight details
    double price = flights["flights"][flightIndex]["price"];
    std::string origin = flights["flights"][flightIndex]["origin"];
    std::string destination = flights["flights"][flightIndex]["destination"];
    std::string departureTime = flights["flights"][flightIndex]["departureTime"];

    // Find current user in users.json
    json* currentUser = nullptr;
    for (auto& user : users["users"]) {
        if (user["username"] == currentUsername.toStdString()) { ////// here the problem
            currentUser = &user;
            break;
        }
    }

    if (!currentUser) {
        QMessageBox::critical(this, "Error", "User not found.");
        return;
    }

    // Get user details
    passengerID = QString::fromStdString((*currentUser)["userID"]);
    int loyaltyPoints = (*currentUser)["loyaltyPoints"];
    double walletBalance = (*currentUser)["wallet"];

    // Calculate discount and new price
    double discount = 0.0;
    if (loyaltyPoints >= 100) {
        discount = 0.10 * (loyaltyPoints / 100);
        if (discount > 0.50) discount = 0.50;
    }
    double discountedPrice = price * (1 - discount);

    // Process payment
    if (paymentMethod == "Wallet") {
        if (walletBalance < discountedPrice) {
            QMessageBox::warning(this, "Warning", "Insufficient wallet balance.");
            return;
        }
        (*currentUser)["wallet"] = walletBalance - discountedPrice;
    }

    // Calculate and add loyalty points (1 point per $10 spent)
    int pointsEarned = static_cast<int>(discountedPrice / 10);
    (*currentUser)["loyaltyPoints"] = loyaltyPoints + pointsEarned;

    // Create reservation
    std::string reservationID = "R" + std::to_string(reservations["reservations"].size() + 1);
    json newReservation = {
        {"reservationID", reservationID},
        {"flightNumber", flightNumber.toStdString()},
        {"passengerID", passengerID.toStdString()},
        {"seatNumber", normalizedSeat.toStdString()}, // Store normalized seat number
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
                            normalizedSeat, // Use normalized seat number in confirmation
                            discountedPrice);

    // Clear fields after booking
    ui->bookFlightNumberLineEdit->clear();
    ui->bookSeatNumberLineEdit->clear();
}
void mainPassengerMenu::showBookingConfirmation(const QString &reservationID, const QString &flightNumber,
                                                const QString &origin, const QString &destination,
                                                const QString &seatNumber, double price)
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

void mainPassengerMenu::on_viewReservationsBtn_clicked()
{
    passengerID = ui->viewUsernameLineEdit->text().trimmed();
    if (passengerID.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter your passenger ID.");
        return;
    }

    json reservationsData = readFromJson("../../data/reservation.json");
    if (reservationsData.is_null()) {
        QMessageBox::critical(this, "Error", "Could not read reservations data.");
        return;
    }

    json passengerReservations = json::array();
    for (const auto &reservation : reservationsData["reservations"]) {
        if (reservation["passengerID"] == passengerID.toStdString()) {
            passengerReservations.push_back(reservation);
        }
    }

    displayReservations(passengerReservations);
}

void mainPassengerMenu::displayReservations(const json &reservations)
{
    ui->reservationsTable->setRowCount(0); // Clear previous results

    if (reservations.empty()) {
        QMessageBox::information(this, "Information", "No reservations found for this passenger.");
        return;
    }

    for (const auto &reservation : reservations) {
        int row = ui->reservationsTable->rowCount();
        ui->reservationsTable->insertRow(row);

        ui->reservationsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(reservation["reservationID"])));
        ui->reservationsTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(reservation["flightNumber"])));

        QString route = QString::fromStdString(reservation["origin"]) + " → " +
                        QString::fromStdString(reservation["destination"]);
        ui->reservationsTable->setItem(row, 2, new QTableWidgetItem(route));

        ui->reservationsTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(reservation["departureTime"])));
        ui->reservationsTable->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(reservation["seatNumber"])));
        ui->reservationsTable->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(reservation["status"])));
    }

    ui->reservationsTable->resizeColumnsToContents();
}

void mainPassengerMenu::on_checkInBtn_clicked()
{
    QString reservationID = ui->checkINReservationIDLineEdit->text().trimmed();
    if (reservationID.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a reservation ID.");
        return;
    }

    json reservations = readFromJson("../../data/reservation.json");
    json flights = readFromJson("../../data/flights.json");
    json users = readFromJson("../../data/users.json");

    if (reservations.is_null() || flights.is_null() || users.is_null()) {
        QMessageBox::critical(this, "Error", "Could not read required data files.");
        return;
    }

    // Find the reservation
    bool found = false;
    for (auto &reservation : reservations["reservations"]) {
        if (reservation["reservationID"] == reservationID.toStdString()) {
            found = true;

            // Check if already confirmed
            if (reservation["status"] == "CONFIRMED") {
                QMessageBox::information(this, "Info", "Reservation is already confirmed.");
                return;
            }

            // Update status
            reservation["status"] = "CONFIRMED";

            // Find flight to get gate
            std::string gate;
            for (const auto &flight : flights["flights"]) {
                if (flight["flightNumber"] == reservation["flightNumber"]) {
                    gate = flight["gate"];
                    break;
                }
            }

            // Find passenger name
            std::string passengerName;
            for (const auto &user : users["users"]) {
                if (user["userID"] == reservation["passengerID"]) {
                    passengerName = user["username"];
                    break;
                }
            }

            // Show boarding pass
            QString boardingPass = QString(
                                       "<h3>Boarding Pass</h3>"
                                       "<p><b>Reservation ID:</b> %1</p>"
                                       "<p><b>Passenger:</b> %2</p>"
                                       "<p><b>Flight:</b> %3</p>"
                                       "<p><b>Route:</b> %4 → %5</p>"
                                       "<p><b>Departure:</b> %6</p>"
                                       "<p><b>Seat:</b> %7</p>"
                                       "<p><b>Gate:</b> %8</p>"
                                       ).arg(
                                           QString::fromStdString(reservation["reservationID"]),
                                           QString::fromStdString(passengerName),
                                           QString::fromStdString(reservation["flightNumber"]),
                                           QString::fromStdString(reservation["origin"]),
                                           QString::fromStdString(reservation["destination"]),
                                           QString::fromStdString(reservation["departureTime"]),
                                           QString::fromStdString(reservation["seatNumber"]),
                                           QString::fromStdString(gate)
                                           );

            QMessageBox::information(this, "Check-In Successful", boardingPass);

            // Write back updated reservations
            if (!writeToJson("../../data/reservation.json", reservations)) {
                QMessageBox::critical(this, "Error", "Failed to save reservation data.");
            }

            break;
        }
    }

    if (!found) {
        QMessageBox::warning(this, "Warning", "Reservation not found.");
    }

    // Clear the field after check-in
    ui->checkINReservationIDLineEdit->clear();
}

json mainPassengerMenu::readFromJson(const QString &filename)
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

bool mainPassengerMenu::writeToJson(const QString &filename, const json &data)
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
