#include "_2a1adminmanageflights.h"
#include "ui__2a1adminmanageflights.h"


adminManageFlights::adminManageFlights(QWidget *parent, Administrator *admin)
    : QDialog(parent)
    , ui(new Ui::adminManageFlights),
    admin(admin),
    currentFlight(nullptr)
{
    ui->setupUi(this);
    resetForm(); // Initialize form in clean state

    connect(ui->assignPilotBtn, &QPushButton::clicked, this, [this]() {
        on_assignPilotBtn_clicked(ui->pilotsTable, ui->attendantsTable);
    });

    connect(ui->updateAssignedCrewBtn, &QPushButton::clicked, this, [this]() {
        on_updateAssignedCrewBtn_clicked();
    });

    connect(ui->viewFlightBtn, &QTabWidget::currentChanged,
            this, [this](int index) {
                if (ui->viewFlightBtn->widget(index) == ui->viewFlightsTab) {
                    viewFlightsIsPressed(); // Call your slot
                }
            });

    setWindowTitle("Admin Dashboard - Mange Flights");

}

void adminManageFlights::resetForm()
{
    m_isResetting = true;
    disconnectAllFieldSignals();

    // Block and clear all fields
    QList<QLineEdit*> lineEdits = findChildren<QLineEdit*>();
    foreach(QLineEdit* lineEdit, lineEdits) {
        lineEdit->blockSignals(true);
        lineEdit->clear();
        lineEdit->blockSignals(false);
    }

    // Reset crew selection
    chosenPilot.clear();
    chosenFA.clear();
    selectedPilots.clear();
    selectedAttendants.clear();
    ui->chosenPilot->setText("Chosen Pilots");
    ui->chosenFA->setText("Chosen Flight Attendants");


    ui->updateChosenPilot->setText("Chosen Pilots");
    ui->updateChosenFA->setText("Chosen Flight Attendants");

    ui->removeChosenPilot->setText("Chosen Pilots");
    ui->removeChosenFA->setText("Chosen Flight Attendants");

    // Reset tables
    ui->pilotsTable->blockSignals(true);
    ui->attendantsTable->blockSignals(true);
    ui->pilotsTable->setRowCount(0);
    ui->attendantsTable->setRowCount(0);
    ui->pilotsTable->blockSignals(false);
    ui->attendantsTable->blockSignals(false);

    ui->updatePilotsTable->blockSignals(true);
    ui->updateAttendantsTable->blockSignals(true);
    ui->updateAttendantsTable->setRowCount(0);
    ui->updatePilotsTable->blockSignals(false);
    ui->updateAttendantsTable->blockSignals(false);
    ui->updatePilotsTable->setRowCount(0);

    // Reset tab
    ui->tabWidget->blockSignals(true);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->blockSignals(false);

    ui->updateCrewTabWidget->blockSignals(true);
    ui->updateCrewTabWidget->setCurrentIndex(0);
    ui->updateCrewTabWidget->blockSignals(false);

    ui->finishFlightBtn->setEnabled(false);
    ui->updateCrewBtn->setEnabled(false);
    ui->removeFlightBtn->setEnabled(false);

    QTimer::singleShot(100, this, [this]() {
        reconnectFieldSignals();
        m_isResetting = false;
    });
}

void adminManageFlights::disconnectAllFieldSignals()
{
    disconnect(ui->nextAddFlightBtn, &QPushButton::clicked, 0, 0);
    disconnect(ui->tabWidget, &QTabWidget::currentChanged, 0, 0);
}

void adminManageFlights::reconnectFieldSignals()
{
    connect(ui->nextAddFlightBtn, &QPushButton::clicked,
            this, &adminManageFlights::on_nextAddFlightBtn_clicked);

    // Add these:
    connect(ui->assignPilotBtn, &QPushButton::clicked, this, [this]() {
        on_assignPilotBtn_clicked(ui->pilotsTable, ui->attendantsTable);
    });

    connect(ui->updateAssignedCrewBtn, &QPushButton::clicked, this, [this]() {
        on_updateAssignedCrewBtn_clicked();
    });

}

bool adminManageFlights::checkForAircraft(QString& aircraft)
{
    bool aircraftExist = false;

    if(!(aircraft.isEmpty()))
    {

        json aircrafts = readFromDP(AirCraftDB);

        int index =isAircraftExist(aircrafts,aircraft.toStdString());

        // Check if the Aircraft exists
        if (index == -1)
        {
            QMessageBox::warning(this,"Error" ,"This Aircraft Does not Exist");
            return false;
        }
        aircraftExist= true;
        json &ac = aircrafts["aircraft"][index];

        if (aircraftExist) {
            qDebug() << "aircraft is existing";
            if(ac["availability"] == false)
            {
                if (oldAircraftID == aircraftID) {
                    qDebug() << "aircraft is avaliable as it the same";
                    return true;
                }
                else if(oldAircraftID!= aircraftID)
                {
                    qDebug() << "aircraft is not avaliable";
                    QMessageBox::warning(this, "Not Available", "The aircraft is not Available.");
                    return false;
                }
            }
            else
            {
                qDebug() << "aircraft is avaliable";
            }
        }
        else
        {
            qDebug() << "aircraft is not existing";
            QMessageBox::information(this, "No Flights", "The aircraft is not existing.");
            return false;
        }
    }
    return true;
}

void adminManageFlights::setAircraftAvailability(const QString& aircraftID, bool available)
{
    json aircrafts = readFromDP(AirCraftDB);
    int index = isAircraftExist(aircrafts, aircraftID.toStdString());

    if (index != -1) {
        aircrafts["aircraft"][index]["availability"] = available;
        if (!writeToDP(AirCraftDB, aircrafts)) {
            qDebug() << "Failed to update aircraft availability";
        }
    }
}

void adminManageFlights::freeOldAircraft(const QString& oldAircraftID)
{
    if (!oldAircraftID.isEmpty()) {
        setAircraftAvailability(oldAircraftID, true);
    }
}

bool adminManageFlights::validateForm(QString &aircraftID)
{
    if (m_isResetting) return true;


    if (currentFlightNumber.isEmpty() ||
        origin.isEmpty() || destination.isEmpty()|| departure.isEmpty()
        || arrival.isEmpty() ||aircraftID.isEmpty()
        ||
        QString::number(status).isEmpty() ||  // Check if status string is empty
        QString::number(maxSeats).isEmpty() || // Check if maxSeats string is empty
        QString::number(price).isEmpty() ||    // Check if price string is empty
        gate.isEmpty())
    {
        if (!m_isResetting) {
            QMessageBox::warning(this, "Error", "Please fill all required fields");

        }
        return false;
    }

    QString validateAircraft = aircraftID;
    bool state =checkForAircraft(validateAircraft);
    if(state)
        return true;
    else
        return false;
}


/*ADD NEW FLIGHT FUNCTIONS*/
/***********************************************************************************/

void adminManageFlights::on_nextAddFlightBtn_clicked()
{
    // Validate basic flight info first
    currentFlightNumber = ui->FlightNumberlineEdit->text().trimmed();
    origin = ui->originlineEdit->text().trimmed();
    destination = ui->destinationlineEdit->text().trimmed();
    departure = ui->departurelineEdit->text().trimmed();
    arrival = ui->ArrivalelineEdit->text().trimmed();
    aircraftID = ui->aircraftIDlineEdit->text().trimmed();
    status = ui->statuslineEdit->text().toInt();
    maxSeats = ui->maxSeatlineEdit->text().toInt();
    price = ui->pricelineEdit->text().toDouble();
    gate = ui->gatelineEdit->text().trimmed();

    if (currentFlightNumber.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a flight number");
        return;
    }

    bool currentState = validateForm(aircraftID);
    if(!currentState)
    {
        return;
    }

    ui->FlightNumberLabel->setText(currentFlightNumber); // Display in UI

    // Load crew data for assignment
    loadCrewData(ui->pilotsTable, ui->attendantsTable);

    // Switch to crew assignment tab
    ui->tabWidget->setCurrentIndex(1);
}

void adminManageFlights::loadCrewData( QTableWidget *pilotsTable , QTableWidget *attendantsTable)
{
    // Load ALL pilots (not just FREE ones)
    json pilotsData = readFromDP(pilotDP);
    pilotsTable->setRowCount(0);

    for (const auto& pilot : pilotsData["pilots"]) {
        int row = pilotsTable->rowCount();
        pilotsTable->insertRow(row);

        pilotsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(pilot["ID"])));
        pilotsTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(pilot["name"])));
        pilotsTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(pilot["status"])));

        // Disable row if pilot is busy
        if (pilot["status"] == "BUSY") {
            for (int col = 0; col < pilotsTable->columnCount(); ++col) {
                QTableWidgetItem* item = pilotsTable->item(row, col);
                if (item) item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
            }
        }
    }

    // Similar change for flight attendants
    json attendantsData = readFromDP(flightAttendantDB);
    attendantsTable->setRowCount(0);

    for (const auto& attendant : attendantsData["flight_attendants"]) {
        int row = attendantsTable->rowCount();
        attendantsTable->insertRow(row);

        attendantsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(attendant["ID"])));
        attendantsTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(attendant["name"])));
        attendantsTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(attendant["status"])));

        QWidget* widget = new QWidget();
        QHBoxLayout* layout = new QHBoxLayout(widget);
        QCheckBox* selectBox = new QCheckBox(widget);
        selectBox->setEnabled(attendant["status"] == "FREE"); // Disable if busy
        layout->addWidget(selectBox);
        layout->setAlignment(Qt::AlignCenter);
        layout->setContentsMargins(0,0,0,0);
        attendantsTable->setCellWidget(row, 3, widget);
    }
}

void adminManageFlights::on_assignPilotBtn_clicked(QTableWidget *pilotsTable , QTableWidget *attendantsTable)
{
    selectedPilots.clear();
    selectedAttendants.clear();

    // Get selected pilot (single selection)
    QModelIndexList selectedPilotIndexes = pilotsTable->selectionModel()->selectedRows();
    if (!selectedPilotIndexes.isEmpty()) {
        int selectedRow = selectedPilotIndexes.first().row();
        selectedPilots.append(pilotsTable->item(selectedRow, 0)->text());
    }

    // Get selected attendants (multiple selection)
    for (int i = 0; i < attendantsTable->rowCount(); ++i) {
        QWidget* widget = attendantsTable->cellWidget(i, 3);
        if (widget) {
            QCheckBox* checkBox = widget->findChild<QCheckBox*>();
            if (checkBox && checkBox->isChecked()) {
                selectedAttendants.append(attendantsTable->item(i, 0)->text());
            }
        }
    }

    // Validation
    if (selectedPilots.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select a pilot");
        return;
    }
    if (selectedAttendants.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select at least one flight attendant");
        return;
    }
    updateAssignedCrewDisplay(pilotsTable,attendantsTable,ui->chosenPilot, ui->chosenFA);
    ui->finishFlightBtn->setEnabled(true);

}

void adminManageFlights::updateAssignedCrewDisplay(QTableWidget *pilotsTable, QTableWidget *attendantsTable,QLabel*chosenPilot,QLabel* chosenFA)

{
    if (!selectedPilots.isEmpty()) {
        // Get pilot name for display
        QString pilotName;
        for (int i = 0; i < pilotsTable->rowCount(); ++i) {
            if (pilotsTable->item(i, 0)->text() == selectedPilots.first()) {
                pilotName = pilotsTable->item(i, 1)->text();
                break;
            }
        }
        chosenPilot->setText(QString("%1 (%2)").arg(pilotName).arg(selectedPilots.first()));
    }

    if (!selectedAttendants.isEmpty()) {
        QStringList attendantNames;
        for (const QString& id : selectedAttendants) {
            for (int i = 0; i < attendantsTable->rowCount(); ++i) {
                if (attendantsTable->item(i, 0)->text() == id) {
                    attendantNames << QString("%1 (%2)").arg(attendantsTable->item(i, 1)->text()).arg(id);
                    break;
                }
            }
        }
        chosenFA->setText(attendantNames.join(", "));
    }
}

void adminManageFlights::on_finishFlightBtn_clicked()
{
    if (m_isResetting) return;

    // First verify we have a flight number
    if (currentFlightNumber.isEmpty()) {
        QMessageBox::warning(this, "Error", "No flight number specified");
        return;
    }

    // Get all flight data from UI
    QString origin = ui->originlineEdit->text().trimmed();
    QString destination = ui->destinationlineEdit->text().trimmed();
    QString departure = ui->departurelineEdit->text().trimmed();
    QString arrival = ui->ArrivalelineEdit->text().trimmed();
    QString aircraftID = ui->aircraftIDlineEdit->text().trimmed();
    int status = ui->statuslineEdit->text().toInt();
    int maxSeats = ui->maxSeatlineEdit->text().toInt();
    double price = ui->pricelineEdit->text().toDouble();
    QString gate = ui->gatelineEdit->text().trimmed();

    // Validate required fields
    if (origin.isEmpty() || destination.isEmpty() || departure.isEmpty() ||
        arrival.isEmpty() || aircraftID.isEmpty() || gate.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill all required fields");
        return;
    }

    // Convert Qt types to std::string for Flight class
    std::string stdOrigin = origin.toStdString();
    std::string stdDestination = destination.toStdString();
    std::string stdDeparture = departure.toStdString();
    std::string stdArrival = arrival.toStdString();
    stdAircraftID = aircraftID.toStdString();
    std::string stdGate = gate.toStdString();
    std::string stdFlightNumber = currentFlightNumber.toStdString();

    // Convert to uppercase for consistency
    std::transform(stdFlightNumber.begin(), stdFlightNumber.end(), stdFlightNumber.begin(), ::toupper);

    flightStatus FSstatus = intStatusToflightStatus(status);

    // Prepare crew assignment
    AssignedCrew crew;
    if (!selectedPilots.isEmpty()) {
        crew.pilotID.push_back(selectedPilots.first().toStdString());
    }
    for (const QString& attendant : selectedAttendants) {
        crew.flightAttendantIDs.push_back(attendant.toStdString());
    }

    try {
        qDebug() << "Attempting to add flight:" << QString::fromStdString(stdFlightNumber);

        // Read existing flights
        json flights;
        try {
            flights = readFromDP(flightDP);
            if (!flights.contains("flights")) {
                flights["flights"] = json::array();
                qDebug() << "Initialized empty flights array";
            }
        } catch (const std::exception& e) {
            qDebug() << "Error reading flight database:" << e.what();
            throw std::runtime_error("Failed to read flight database");
        }

        // Case-insensitive flight existence check
        auto toLower = [](std::string s) {
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s;
        };

        bool flightExists = false;
        qDebug() << "Checking existing flights:";
        for (const auto& f : flights["flights"]) {
            std::string existingNumber = f["flightNumber"];
            qDebug() << "- Existing flight:" << QString::fromStdString(existingNumber);

            if (toLower(existingNumber) == toLower(stdFlightNumber)) {
                flightExists = true;
                break;
            }
        }

        if (flightExists) {
            throw std::runtime_error("Flight with this number already exists");
        }
        setAircraftAvailability(aircraftID, false);

        // Create new flight
        Flight newFlight(stdFlightNumber, stdOrigin, stdDestination,
                         stdDeparture, stdArrival, FSstatus, stdAircraftID,
                         crew, maxSeats, price, stdGate);

        // Add to flights array
        flights["flights"].push_back(newFlight.toJson());

        // Write to database
        if (!writeToDP(flightDP, flights)) {
            throw std::runtime_error("Failed to write to flight database");
        }

        // Update crew status
        try {
            if (!selectedPilots.isEmpty()) {
                updateCrewStatus(selectedPilots.first(), selectedAttendants, currentFlightNumber);
            }
        } catch (const std::exception& e) {
            qDebug() << "Warning: Failed to update crew status:" << e.what();
            // Continue even if crew status update fails
        }

        QMessageBox::information(this, "Success", "The flight added successfully");
        resetForm();

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to add flight: %1").arg(e.what()));
        qDebug() << "Error details:" << e.what();
    }
}

void adminManageFlights::updateCrewStatus(const QString &pilotID, const QStringList &attendantIDs, const QString &flightNumber)
{
    // Update pilot status - should use first() since we only allow single selection
    json pilots = readFromDP(pilotDP);
    for (auto& pilot : pilots["pilots"]) {
        if (pilot["ID"] == pilotID.toStdString()) { // This is correct if pilotID is a single ID
            pilot["status"] = "BUSY";
            pilot["assignedFlight"] = flightNumber.toStdString();
            break;
        }
    }

    // Add error checking
    if (!writeToDP(pilotDP, pilots)) {
        qDebug() << "Failed to write pilot data";
        throw std::runtime_error("Failed to update pilot status");
    }

    // Update flight attendants status
    json attendants = readFromDP(flightAttendantDB);
    for (const QString& attendantID : attendantIDs) {
        for (auto& attendant : attendants["flight_attendants"]) {
            if (attendant["ID"] == attendantID.toStdString()) {
                attendant["status"] = "BUSY";
                attendant["assignedFlight"] = flightNumber.toStdString();
                break;
            }
        }
    }

    // Add error checking
    if (!writeToDP(flightAttendantDB, attendants)) {
        qDebug() << "Failed to write attendant data";
        throw std::runtime_error("Failed to update attendant status");
    }
}

/**************************************************************************************************/

//UPDATE FLIGHT FUNCTIONS
void adminManageFlights::on_searchOnFlightToUpdate_clicked(){
    try {
        // Read flight data from database
        json flights = readFromDP(flightDP);

        // Check if there are any flights
        if (flights["flights"].empty()) {
            QMessageBox::information(this, "No Flights", "The flight database is empty.");
            return;
        }

        currentFlightNumber = ui->updateFlightNumberlineEdit->text().trimmed().toUpper();

        bool flightFound = false;

        // Search for the flight
        for (auto& flight : flights["flights"]) {
            std::string flightNumber = flight["flightNumber"];
            if (QString::fromStdString(flightNumber).toUpper() == currentFlightNumber) {
                flightFound = true;

                // Helper function to safely get JSON values
                auto getValue = [&flight](const char* key) -> QString {
                    if (flight.contains(key)) {
                        auto value = flight[key];
                        if (value.is_string()) {
                            return QString::fromStdString(value.get<std::string>());
                        } else if (value.is_number_integer()) {
                            return QString::number(value.get<int>());
                        } else if (value.is_number_float()) {
                            return QString::number(value.get<double>());
                        } else if (value.is_boolean()) {
                            return value.get<bool>() ? "true" : "false";
                        }
                    }
                    return "";
                };

                // Set all flight data in UI fields
                ui->updateOriginlineEdit->setText(getValue("origin"));
                ui->updateDestinationlineEdit->setText(getValue("destination"));
                ui->updateDeparturelineEdit->setText(getValue("departureTime"));
                ui->updateArrivalelineEdit->setText(getValue("arrivalTime"));
                ui->updateAircraftIDlineEdit->setText(getValue("aircraftID"));
                ui->updateStatuslineEdit->setText(getValue("status"));
                ui->updateMaxSeatlineEdit->setText(getValue("maxSeats"));
                ui->updatePricelineEdit->setText(getValue("price"));
                ui->updateGatelineEdit->setText(getValue("gate"));

            }
        }

        if (!flightFound) {
            QMessageBox::warning(this, "Not Found",
                                 QString("Flight %1 not found in database.").arg(currentFlightNumber));
        }

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to search for flight: %1").arg(e.what()));
        qDebug() << "Error details:" << e.what();
    }
}

void adminManageFlights::on_updateFlightBtn_clicked()
{
    // Read existing flights from the file
    json flights = readFromDP(flightDP);
    json aircrafts = readFromDP(AirCraftDB);


    if (flights["flights"].empty()) {
        QMessageBox::information(this, "No Flights", "The flight database is empty.");
        return;
    }

    currentFlightNumber = ui->updateFlightNumberlineEdit->text().trimmed().toUpper();
    aircraftID = ui->updateAircraftIDlineEdit->text().trimmed();


    int index = isFlightExists(flights, currentFlightNumber.toStdString());
    int aircraftIndex = isAircraftExist(aircrafts, aircraftID.toStdString());

    // Get the old aircraft ID before updating
    oldAircraftID = QString::fromStdString(flights["flights"][index]["aircraftID"]);


    // Check if the flight exists
    if (index == -1)
    {
        QMessageBox::information(this,"Error" ,"This Flight Number Does not Exist");
        return;
    }
    json &flight = flights["flights"][index];
    json &ac = aircrafts["aircraft"][aircraftIndex];

    // Get all flight data from UI
    origin = ui->updateOriginlineEdit->text().trimmed();
    destination = ui->updateDestinationlineEdit->text().trimmed();
    departure = ui->updateDeparturelineEdit->text().trimmed();
    arrival = ui->updateArrivalelineEdit->text().trimmed();
    aircraftID = ui->updateAircraftIDlineEdit->text().trimmed();
    status = ui->updateStatuslineEdit->text().toInt();
    maxSeats = ui->updateMaxSeatlineEdit->text().toInt();
    price = ui->updatePricelineEdit->text().toDouble();
    gate = ui->updateGatelineEdit->text().trimmed();

    bool state = validateForm(aircraftID);
    if(state)
    {
        qDebug() <<"Aircraft is existed and all field is filled\n";
    }
    else
    {
        return;
    }


    // Convert Qt types to std::string for Flight class
    std::string stdOrigin = origin.toStdString();
    std::string stdDestination = destination.toStdString();
    std::string stdDeparture = departure.toStdString();
    std::string stdArrival = arrival.toStdString();
    stdAircraftID = aircraftID.toStdString();
    std::string stdGate = gate.toStdString();
    std::string stdFlightNumber = currentFlightNumber.toStdString();
    // Convert to uppercase for consistency
    std::transform(stdFlightNumber.begin(), stdFlightNumber.end(), stdFlightNumber.begin(), ::toupper);
    std::string SSstatus = intStatusToStringStatus(status);

    //push the new data

    flight["flightNumber"]=currentFlightNumber.toStdString();
    flight["origin"] = stdOrigin;
    flight["destination"]= stdDestination;
    flight["departureTime"]=stdDeparture;
    flight["arrivalTime"]= stdArrival;
    flight["aircraftID"]= stdAircraftID;
    flight["status"]= SSstatus;
    flight["maxSeats"]=maxSeats;
    flight["price"]= price;
    flight["gate"]= stdGate;

    // Write the updated data back to file
    if (!writeToDP(flightDP, flights)) {
        QMessageBox::critical(this, "Error", "Failed to update flight in database");
        return;
    }


    // Only free old aircraft and mark new one unavailable if aircraft ID has changed
    if (oldAircraftID != aircraftID) {
        // Free the old aircraft
        freeOldAircraft(oldAircraftID);
        // Mark new aircraft as unavailable
        setAircraftAvailability(aircraftID, false);
    }

    QMessageBox::information(this, "Success", "Flight updated successfully");
    // Clear only the update form fields
    ui->updateFlightNumberlineEdit->clear();
    ui->updateOriginlineEdit->clear();
    ui->updateDestinationlineEdit->clear();
    ui->updateDeparturelineEdit->clear();
    ui->updateArrivalelineEdit->clear();
    ui->updateAircraftIDlineEdit->clear();
    ui->updateStatuslineEdit->clear();
    ui->updateMaxSeatlineEdit->clear();
    ui->updatePricelineEdit->clear();
    ui->updateGatelineEdit->clear();
}

void adminManageFlights::on_searchOnFlightToUpdateCrew_clicked()
{
    try {
        // Read flight data from database
        json flights = readFromDP(flightDP);

        // Check if there are any flights
        if (flights["flights"].empty()) {
            QMessageBox::information(this, "No Flights", "The flight database is empty.");
            return;
        }

        // Get flight number from the CREW tab's line edit
        currentFlightNumber = ui->updateCrewFlightNumberlineEdit->text().trimmed().toUpper();

        if (currentFlightNumber.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please enter a flight number");
            return;
        }

        bool flightFound = false;
        json flightData;

        // Search for the flight
        for (auto& flight : flights["flights"]) {
            std::string flightNumber = flight["flightNumber"];
            if (QString::fromStdString(flightNumber).toUpper() == currentFlightNumber) {
                flightFound = true;
                flightData = flight;
                break;
            }
        }

        if (!flightFound) {
            QMessageBox::warning(this, "Not Found",
                                 QString("Flight %1 not found in database.").arg(currentFlightNumber));
            return;
        }

        // Store the currently assigned crew (to free them later if changed)
        previousPilots.clear();
        previousAttendants.clear();

        // Get currently assigned crew
        for (const auto& pilot : flightData["assignedCrew"]["pilotID"]) {
            previousPilots.append(QString::fromStdString(pilot));
        }
        for (const auto& attendant : flightData["assignedCrew"]["flightAttendantIDs"]) {
            previousAttendants.append(QString::fromStdString(attendant));
        }

        // Load all crew members with selection widgets
        loadCrewDataWithSelection(ui->updatePilotsTable, ui->updateAttendantsTable, flightData);

        // Enable update button
        ui->updateCrewBtn->setEnabled(true);

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to search for flight: %1").arg(e.what()));
        qDebug() << "Error details:" << e.what();
    }
}

void adminManageFlights::loadCrewDataWithSelection(QTableWidget* pilotsTable, QTableWidget* attendantsTable, const json& flightData)
{
    // Clear tables
    pilotsTable->setRowCount(0);
    attendantsTable->setRowCount(0);

    // Load pilots data with radio buttons
    json pilotsData = readFromDP(pilotDP);
    QButtonGroup* pilotGroup = new QButtonGroup(this);

    for (const auto& pilot : pilotsData["pilots"]) {
        int row = pilotsTable->rowCount();
        pilotsTable->insertRow(row);

        // Add pilot data
        pilotsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(pilot["ID"])));
        pilotsTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(pilot["name"])));
        pilotsTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(pilot["status"])));

        // Add radio button for selection
        QWidget* widget = new QWidget();
        QHBoxLayout* layout = new QHBoxLayout(widget);
        QRadioButton* radioBtn = new QRadioButton(widget);

        // Check if this pilot is currently assigned to the flight
        bool isAssigned = false;
        for (const auto& assignedPilot : flightData["assignedCrew"]["pilotID"]) {
            if (assignedPilot == pilot["ID"]) {
                isAssigned = true;
                break;
            }
        }
        radioBtn->setChecked(isAssigned);

        // Disable if pilot is busy and not currently assigned to this flight
        if (pilot["status"] == "BUSY" && !isAssigned) {
            radioBtn->setEnabled(false);
        }

        layout->addWidget(radioBtn);
        layout->setAlignment(Qt::AlignCenter);
        layout->setContentsMargins(0, 0, 0, 0);
        pilotsTable->setCellWidget(row, 3, widget);
        pilotGroup->addButton(radioBtn, row);
    }

    // Load flight attendants data with checkboxes
    json attendantsData = readFromDP(flightAttendantDB);

    for (const auto& attendant : attendantsData["flight_attendants"]) {
        int row = attendantsTable->rowCount();
        attendantsTable->insertRow(row);

        // Add attendant data
        attendantsTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(attendant["ID"])));
        attendantsTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(attendant["name"])));
        attendantsTable->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(attendant["status"])));

        // Add checkbox for selection
        QWidget* widget = new QWidget();
        QHBoxLayout* layout = new QHBoxLayout(widget);
        QCheckBox* checkBox = new QCheckBox(widget);

        // Check if this attendant is currently assigned to the flight
        bool isAssigned = false;
        for (const auto& assignedAttendant : flightData["assignedCrew"]["flightAttendantIDs"]) {
            if (assignedAttendant == attendant["ID"]) {
                isAssigned = true;
                break;
            }
        }
        checkBox->setChecked(isAssigned);

        // Disable if attendant is busy and not currently assigned to this flight
        if (attendant["status"] == "BUSY" && !isAssigned) {
            checkBox->setEnabled(false);
        }

        layout->addWidget(checkBox);
        layout->setAlignment(Qt::AlignCenter);
        layout->setContentsMargins(0, 0, 0, 0);
        attendantsTable->setCellWidget(row, 3, widget);
    }
}

void adminManageFlights::on_updateAssignedCrewBtn_clicked()
{
    // Clear previous selections
    selectedPilots.clear();
    selectedAttendants.clear();

    // Get selected pilot
    for (int i = 0; i < ui->updatePilotsTable->rowCount(); ++i) {
        QWidget* widget = ui->updatePilotsTable->cellWidget(i, 3);
        if (widget) {
            QRadioButton* radioBtn = widget->findChild<QRadioButton*>();
            if (radioBtn && radioBtn->isChecked()) {
                selectedPilots.append(ui->updatePilotsTable->item(i, 0)->text());
                break;
            }
        }
    }

    // Get selected attendants
    for (int i = 0; i < ui->updateAttendantsTable->rowCount(); ++i) {
        QWidget* widget = ui->updateAttendantsTable->cellWidget(i, 3);
        if (widget) {
            QCheckBox* checkBox = widget->findChild<QCheckBox*>();
            if (checkBox && checkBox->isChecked()) {
                selectedAttendants.append(ui->updateAttendantsTable->item(i, 0)->text());
            }
        }
    }

    // Update the display
    updateAssignedCrewDisplay(ui->updatePilotsTable, ui->updateAttendantsTable, ui->updateChosenPilot, ui->updateChosenFA);

    // Enable the finish button if we have selections
    if (!selectedPilots.isEmpty() && !selectedAttendants.isEmpty()) {
        ui->updateCrewBtn->setEnabled(true);
    }
}

void adminManageFlights::updateCrewStatusForFlightChange()
{
    // Free the previous crew (set status to FREE and clear assigned flight)
    json pilots = readFromDP(pilotDP);
    for (auto& pilot : pilots["pilots"]) {
        for (const QString& prevPilot : previousPilots) {
            if (pilot["ID"] == prevPilot.toStdString()) {
                pilot["status"] = "FREE";
                pilot["assignedFlight"] = "";
                break;
            }
        }
    }
    if (!writeToDP(pilotDP, pilots)) {
        throw std::runtime_error("Failed to update pilot status");
    }

    json attendants = readFromDP(flightAttendantDB);
    for (auto& attendant : attendants["flight_attendants"]) {
        for (const QString& prevAttendant : previousAttendants) {
            if (attendant["ID"] == prevAttendant.toStdString()) {
                attendant["status"] = "FREE";
                attendant["assignedFlight"] = "";
                break;
            }
        }
    }
    if (!writeToDP(flightAttendantDB, attendants)) {
        throw std::runtime_error("Failed to update attendant status");
    }

    // Set new crew status to BUSY and assign flight
    for (auto& pilot : pilots["pilots"]) {
        if (pilot["ID"] == selectedPilots.first().toStdString()) {
            pilot["status"] = "BUSY";
            pilot["assignedFlight"] = currentFlightNumber.toStdString();
            break;
        }
    }
    if (!writeToDP(pilotDP, pilots)) {
        throw std::runtime_error("Failed to update new pilot status");
    }

    for (auto& attendant : attendants["flight_attendants"]) {
        for (const QString& newAttendant : selectedAttendants) {
            if (attendant["ID"] == newAttendant.toStdString()) {
                attendant["status"] = "BUSY";
                attendant["assignedFlight"] = currentFlightNumber.toStdString();
                break;
            }
        }
    }
    if (!writeToDP(flightAttendantDB, attendants)) {
        throw std::runtime_error("Failed to update new attendant status");
    }
}

void adminManageFlights::on_updateCrewBtn_clicked()
{

    try {
        // Get selected crew from the tables
        selectedPilots.clear();
        selectedAttendants.clear();

        // Get selected pilot (only one can be selected via radio buttons)
        for (int i = 0; i < ui->updatePilotsTable->rowCount(); ++i) {
            QWidget* widget = ui->updatePilotsTable->cellWidget(i, 3);
            if (widget) {
                QRadioButton* radioBtn = widget->findChild<QRadioButton*>();
                if (radioBtn && radioBtn->isChecked()) {
                    selectedPilots.append(ui->updatePilotsTable->item(i, 0)->text());
                    break; // Only one pilot can be selected
                }
            }
        }

        // Get selected attendants (multiple can be selected)
        for (int i = 0; i < ui->updateAttendantsTable->rowCount(); ++i) {
            QWidget* widget = ui->updateAttendantsTable->cellWidget(i, 3);
            if (widget) {
                QCheckBox* checkBox = widget->findChild<QCheckBox*>();
                if (checkBox && checkBox->isChecked()) {
                    selectedAttendants.append(ui->updateAttendantsTable->item(i, 0)->text());
                }
            }
        }

        // Validate selection
        if (selectedPilots.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please select a pilot");
            return;
        }
        if (selectedAttendants.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please select at least one flight attendant");
            return;
        }

        // Read flight data
        json flights = readFromDP(flightDP);
        int flightIndex = -1;

        // Find the flight to update
        for (size_t i = 0; i < flights["flights"].size(); ++i) {
            if (flights["flights"][i]["flightNumber"] == currentFlightNumber.toStdString()) {
                flightIndex = i;
                break;
            }
        }

        if (flightIndex == -1) {
            QMessageBox::warning(this, "Error", "Flight not found in database");
            return;
        }

        // Update crew status in their respective databases
        updateCrewStatusForFlightChange();

        // Update the flight's assigned crew
        json& flight = flights["flights"][flightIndex];
        flight["assignedCrew"]["pilotID"].clear();
        flight["assignedCrew"]["pilotID"].push_back(selectedPilots.first().toStdString());

        flight["assignedCrew"]["flightAttendantIDs"].clear();
        for (const QString& attendant : selectedAttendants) {
            flight["assignedCrew"]["flightAttendantIDs"].push_back(attendant.toStdString());
        }

        // Save the updated flight data
        if (!writeToDP(flightDP, flights)) {
            throw std::runtime_error("Failed to update flight in database");
        }

        QMessageBox::information(this, "Success", "Crew updated successfully");

        resetForm();

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to update crew: %1").arg(e.what()));
        qDebug() << "Error details:" << e.what();
    }
}
/****************************************************************************************************/




/*remove flights*/
void adminManageFlights::on_searchOnFlightToRemove_clicked()
{
    try {
        // Read flight data from database
        json flights = readFromDP(flightDP);

        // Check if there are any flights
        if (flights["flights"].empty()) {
            QMessageBox::information(this, "No Flights", "The flight database is empty.");
            return;
        }

        currentFlightNumber = ui->removeFlightNumberlineEdit->text().trimmed().toUpper();

        bool flightFound = false;

        // Search for the flight
        for (auto& flight : flights["flights"]) {
            std::string flightNumber = flight["flightNumber"];
            if (QString::fromStdString(flightNumber).toUpper() == currentFlightNumber) {
                flightFound = true;

                // Helper function to safely get JSON values
                auto getValue = [&flight](const char* key) -> QString {
                    if (flight.contains(key)) {
                        auto value = flight[key];
                        if (value.is_string()) {
                            return QString::fromStdString(value.get<std::string>());
                        } else if (value.is_number_integer()) {
                            return QString::number(value.get<int>());
                        } else if (value.is_number_float()) {
                            return QString::number(value.get<double>());
                        } else if (value.is_boolean()) {
                            return value.get<bool>() ? "true" : "false";
                        }
                    }
                    return "";
                };

                json pilots = readFromDP(pilotDP);
                json flightAttendants = readFromDP(flightAttendantDB);

                // Get crew names
                QString pilotName, attendantNames;

                // Get pilot name
                if (flight.contains("assignedCrew") && flight["assignedCrew"].contains("pilotID") && !flight["assignedCrew"]["pilotID"].empty()) {
                    std::string pilotID = flight["assignedCrew"]["pilotID"][0];
                    for (const auto& pilot : pilots["pilots"]) {
                        if (pilot["ID"] == pilotID) {
                            pilotName = QString("%1 (%2)").arg(QString::fromStdString(pilot["name"])).arg(QString::fromStdString(pilotID));
                            break;
                        }
                    }
                }

                // Get attendant names
                if (flight.contains("assignedCrew") && flight["assignedCrew"].contains("flightAttendantIDs")) {
                    QStringList attendantsList;
                    for (const auto& attendantID : flight["assignedCrew"]["flightAttendantIDs"]) {
                        for (const auto& attendant : flightAttendants["flight_attendants"]) {
                            if (attendant["ID"] == attendantID) {
                                attendantsList << QString("%1 (%2)").arg(QString::fromStdString(attendant["name"])).arg(QString::fromStdString(attendantID));
                                break;
                            }
                        }
                    }
                    attendantNames = attendantsList.join(", ");
                }

                // Set all flight data in UI fields
                ui->removeOriginlineEdit->setText(getValue("origin"));
                ui->removeDestinationlineEdit->setText(getValue("destination"));
                ui->removeDeparturelineEdit->setText(getValue("departureTime"));
                ui->removeArrivalelineEdit->setText(getValue("arrivalTime"));
                ui->removeAircraftIDlineEdit->setText(getValue("aircraftID"));
                ui->removeStatuslineEdit->setText(getValue("status"));
                ui->removeMaxSeatlineEdit->setText(getValue("maxSeats"));
                ui->removePricelineEdit->setText(getValue("price"));
                ui->removeGatelineEdit->setText(getValue("gate"));
                ui->removeChosenPilot->setText(pilotName);
                ui->removeChosenFA->setText(attendantNames);
                aircraftID = ui->removeAircraftIDlineEdit->text().trimmed().toUpper();
                ui->removeFlightBtn->setEnabled(true);

            }
        }

        if (!flightFound) {
            QMessageBox::warning(this, "Not Found",
                                 QString("Flight %1 not found in database.").arg(currentFlightNumber));
        }

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to search for flight: %1").arg(e.what()));
        qDebug() << "Error details:" << e.what();
    }
}


void adminManageFlights::on_removeFlightBtn_clicked()
{
    // Read flight data from database
    json flights = readFromDP(flightDP);

    try {

        // Check if there are any flights
        if (flights["flights"].empty()) {
            QMessageBox::information(this, "No Flights", "The flight database is empty.");
            return;
        }

        currentFlightNumber = ui->removeFlightNumberlineEdit->text().trimmed().toUpper();

        bool flightFound = false;

        // Search for the flight
        for (auto& flight : flights["flights"]) {
            std::string flightNumber = flight["flightNumber"];
            if (QString::fromStdString(flightNumber).toUpper() == currentFlightNumber) {
                flightFound = true;
            }
        }

        if (!flightFound) {
            QMessageBox::warning(this, "Not Found",
                                 QString("Flight %1 not found in database.").arg(currentFlightNumber));
        }

        // Read existing flights, pilots, flight attendants, and aircraft from their files
        json pilots = readFromDP(pilotDP);
        json flightAttendants = readFromDP(flightAttendantDB);
        json aircrafts = readFromDP(AirCraftDB); // Assuming you have an aircraft database

        int index = isFlightExists(flights, currentFlightNumber.toStdString());
        json &flight = flights["flights"][index];

        // Check if the flight has assigned crew
        if (flight.contains("assignedCrew"))
        {
            // Free the assigned pilots
            for (const auto &pilotID : flight["assignedCrew"]["pilotID"])
            {
                for (auto &pilot : pilots["pilots"])
                {
                    if (pilot["ID"] == pilotID)
                    {
                        pilot["status"] = "FREE";     // Set status to Available
                        pilot["assignedFlight"] = ""; // Remove the assigned flight
                        break;
                    }
                }
            }

            // Free the assigned flight attendants
            for (const auto &faID : flight["assignedCrew"]["flightAttendantIDs"])
            {
                for (auto &fa : flightAttendants["flight_attendants"])
                {
                    if (fa["ID"] == faID)
                    {
                        fa["status"] = "FREE";     // Set status to Available
                        fa["assignedFlight"] = ""; // Remove the assigned flight
                        break;
                    }
                }
            }

            qDebug() << "Crew members assigned to flight " << currentFlightNumber << " have been marked as available.\n";
        }
        // Free the aircraft - this is the critical fix
        if (flight.contains("aircraftID")) {
            QString aircraftID = QString::fromStdString(flight["aircraftID"]);
            int aircraftIndex = isAircraftExist(aircrafts, aircraftID.toStdString());
            if (aircraftIndex != -1) {
                aircrafts["aircraft"][aircraftIndex]["availability"] = true;
            }
        }

        // Delete the flight
        flights["flights"].erase(flights["flights"].begin() + index);
        qDebug() << "Flight with number " << currentFlightNumber << " has been successfully deleted.\n";

        // Write the updated data back to the files
        writeToDP(flightDP, flights);
        writeToDP(pilotDP, pilots);
        writeToDP(flightAttendantDB, flightAttendants);
        writeToDP(AirCraftDB, aircrafts); // Save the updated aircraft status

        QMessageBox::information(this, "Remove Flight", QString("The flight %1 has been removed successfully.").arg(currentFlightNumber));

        ui->removeFlightNumberlineEdit->clear();
        ui->removeOriginlineEdit->clear();
        ui->removeDestinationlineEdit->clear();
        ui->removeDeparturelineEdit->clear();
        ui->removeArrivalelineEdit->clear();
        ui->removeAircraftIDlineEdit->clear();
        ui->removeStatuslineEdit->clear();
        ui->removeMaxSeatlineEdit->clear();
        ui->removePricelineEdit->clear();
        ui->removeGatelineEdit->clear();
        ui->removeChosenPilot->clear();
        ui->removeChosenFA->clear();
        resetForm();
        return;

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to search for flight: %1").arg(e.what()));
        qDebug() << "Error details:" << e.what();
    }



}
/****************************************************************************/
/*View All Flights*/

void adminManageFlights::updateFlightTable(const QJsonArray& flights)
{
    QTableWidget* table = ui->viewTableWidget;
    table->clearContents();
    table->setRowCount(flights.size());

    for (int row = 0; row < flights.size(); ++row) {
        QJsonObject flight = flights[row].toObject();

        // Create items with centered alignment
        QTableWidgetItem* flightNoItem = new QTableWidgetItem(flight["flightNumber"].toString());
        QTableWidgetItem* originItem = new QTableWidgetItem(flight["origin"].toString());
        QTableWidgetItem* destItem = new QTableWidgetItem(flight["destination"].toString());
        QTableWidgetItem* depTimeItem = new QTableWidgetItem(flight["departureTime"].toString());
        QTableWidgetItem* arrTimeItem = new QTableWidgetItem(flight["arrivalTime"].toString());
        QTableWidgetItem* aircraftItem = new QTableWidgetItem(flight["aircraftID"].toString());
        QTableWidgetItem* statusItem = new QTableWidgetItem(flight["status"].toString());
        QTableWidgetItem* gateItem = new QTableWidgetItem(flight["gate"].toString());
        QTableWidgetItem* priceItem = new QTableWidgetItem(
            QString::number(flight["price"].toDouble(), 'f', 2));
        QTableWidgetItem* maxSeatsItem = new QTableWidgetItem(
            QString::number(flight["maxSeats"].toInt()));
        QTableWidgetItem* availSeatsItem = new QTableWidgetItem(
            QString::number(flight["availableSeats"].toInt()));

        // Set center alignment for all items
        flightNoItem->setTextAlignment(Qt::AlignCenter);
        originItem->setTextAlignment(Qt::AlignCenter);
        destItem->setTextAlignment(Qt::AlignCenter);
        depTimeItem->setTextAlignment(Qt::AlignCenter);
        arrTimeItem->setTextAlignment(Qt::AlignCenter);
        aircraftItem->setTextAlignment(Qt::AlignCenter);
        statusItem->setTextAlignment(Qt::AlignCenter);
        gateItem->setTextAlignment(Qt::AlignCenter);
        priceItem->setTextAlignment(Qt::AlignCenter);
        maxSeatsItem->setTextAlignment(Qt::AlignCenter);
        availSeatsItem->setTextAlignment(Qt::AlignCenter);

        // Set items in table
        table->setItem(row, 0, flightNoItem);
        table->setItem(row, 1, originItem);
        table->setItem(row, 2, destItem);
        table->setItem(row, 3, depTimeItem);
        table->setItem(row, 4, arrTimeItem);
        table->setItem(row, 5, aircraftItem);
        table->setItem(row, 6, statusItem);
        table->setItem(row, 7, gateItem);
        table->setItem(row, 8, priceItem);
        table->setItem(row, 9, maxSeatsItem);
        table->setItem(row, 10, availSeatsItem);

        // Handle crew - separate columns
        QJsonObject crew = flight["assignedCrew"].toObject();
        QJsonArray pilots = crew["pilotID"].toArray();
        QJsonArray attendants = crew["flightAttendantIDs"].toArray();

        // Pilots column (index 11)
        QString pilotString = pilots.isEmpty() ? "None" : pilots[0].toString();
        QTableWidgetItem* pilotItem = new QTableWidgetItem(pilotString);
        pilotItem->setTextAlignment(Qt::AlignCenter);
        table->setItem(row, 11, pilotItem);

        // Flight Attendants column (index 12)
        QString attendantsString = "None";
        if (!attendants.isEmpty()) {
            attendantsString = "";
            for (int i = 0; i < attendants.size(); ++i) {
                attendantsString += attendants[i].toString();
                if (i < attendants.size() - 1) {
                    attendantsString += ", ";
                }
            }
        }
        QTableWidgetItem* faItem = new QTableWidgetItem(attendantsString);
        faItem->setTextAlignment(Qt::AlignCenter);
        table->setItem(row, 12, faItem);
    }

    table->resizeColumnsToContents();
    table->horizontalHeader()->setStretchLastSection(true);
}

void adminManageFlights::viewFlightsIsPressed()
{
    // Load from file (or your actual data source)
    QFile jsonFile("../../data/flights.json");  // Adjust path as needed
    if (!jsonFile.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Could not open flights data file");
        return;
    }

    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (doc.isNull() || !doc.isObject()) {
        QMessageBox::warning(this, "Error", "Invalid flights data format");
        return;
    }

    QJsonObject jsonObj = doc.object();
    QJsonArray flightsArray = jsonObj["flights"].toArray();

    updateFlightTable(flightsArray);
}


/*****************************************************************************/
adminManageFlights::~adminManageFlights()
{
    delete ui;
}






