#include "_2a2adminmangeaircraft.h"
#include "ui__2a2adminmangeaircraft.h"

adminMangeAircraft::adminMangeAircraft(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminMangeAircraft)
{
    ui->setupUi(this);

    connect(ui->aircraftTabWidget, &QTabWidget::currentChanged,
            this, [this](int index) {
                if (ui->aircraftTabWidget->widget(index) == ui->viewAircraftTab) {
                    viewAllAirCrafts(); // Call your slot
                }
            });

    setWindowTitle("Admin Dashboard - Mange Aircrafts");

}

void adminMangeAircraft::on_addAircraftBtn_clicked()
{

    // Validate basic flight info first
    aircraftID= ui->aircraftIDlineEdit->text().trimmed();
    assignedFlight= ui->aircraftAssignedFlightlineEdit->text().trimmed();
    availability= ui->aircraftAvalineEdit->text().trimmed();
    maintenanceSchedule= ui->aircraftMainSchelineEdit->text().trimmed();
    model= ui->aircraftModellineEdit->text().trimmed();



    if (aircraftID.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a Aircraft ID");
        return;
    }
    else if(assignedFlight.isEmpty() && availability.contains("0"))
    {
        QMessageBox::warning(this, "Error", "You cant make the Aircraft Unavailable and u didn't"
                                            "assign a Flight");
        return;
    }
    else if (!(assignedFlight.isEmpty()) && availability.contains("1"))
    {
        QMessageBox::warning(this, "Error", "You cant make the Aircraft available and u "
                                            "assigned a Flight");
        return;
    }
    else if(availability.isEmpty() ||  ((! availability.contains("0")) && (! availability.contains("1")))  )
    {
        QMessageBox::warning(this, "Error", "Please enter the Aircraft status: 0 For False and 1 For True");
        return;
    }
    else if(model.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter a Aircraft Model");
        return;
    }
    else if (maintenanceSchedule.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter a Aircraft Maintenance Schedule");
        return;
    }

    bool avaState = false;
    // Convert Qt types to std::string for Flight class
    std::string stdaircraftID = aircraftID.toStdString();
    std::string stdassignedFlight = assignedFlight.toStdString();
    std::string stdavailability = availability.toStdString();
    avaState = (stdavailability == "1");  // Default case (false if not "1")
    std::string stdmaintenanceSchedule = maintenanceSchedule.toStdString();
    std::string stdmodel = model.toStdString();

    // Convert to uppercase for consistency
    std::transform(stdaircraftID.begin(), stdaircraftID.end(), stdaircraftID.begin(), ::toupper);

    try {
        qDebug() << "Attempting to add Aircraft:" << QString::fromStdString(stdaircraftID);

        // Read existing flights
        json flights;
        json aircrafts;
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

        try {
            aircrafts= readFromDP(AirCraftDB);
            if(!aircrafts.contains("aircraft"))
            {
                aircrafts["aircraft"] = json::array();
                qDebug() << "Initialized empty aircraft array";
            }

        } catch (const std::exception& e) {
            qDebug() << "Error reading aircraft database:" << e.what();
            throw std::runtime_error("Failed to read aircraft database");
        }



        // Case-sensitive flight existence check
        auto toLower = [](std::string s) {
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            return s;
        };

        bool flightExists = false;
        qDebug() << "Checking existing flights:";
        for (const auto& a : aircrafts["aircraft"]) {
            std::string existingAssignedFlight = a["assignedFlight"];
            qDebug() << "- Existing flight:" << QString::fromStdString(existingAssignedFlight);
            if(stdassignedFlight.empty())
                break;
            if (toLower(existingAssignedFlight) == toLower(stdassignedFlight)) {
                flightExists = true;
                break;
            }
        }

        bool aircraftExist = false;
        qDebug() << "Checking existing aircrafts:";
        for(const auto&a: aircrafts["aircraft"])
        {
            std::string existingID = a["aircraftID"];
            qDebug() << "- Existing aircrafts:" << QString::fromStdString(existingID);

            if (toLower(existingID) == toLower(stdaircraftID)) {
                aircraftExist = true;
                break;
            }

        }


        if (flightExists) {
            throw std::runtime_error("Flight with this number already assigned to another aircraft.");
        }

        if (aircraftExist) {
            throw std::runtime_error("Aircraft with this number already exists");
        }

        Aircraft currentAircraft(stdaircraftID, stdmodel,stdmaintenanceSchedule,avaState, stdassignedFlight);

        // Add to flights array
        aircrafts["aircraft"].push_back(currentAircraft.toJson());

        // Write to database
        if (!writeToDP(AirCraftDB, aircrafts)) {
            throw std::runtime_error("Failed to write to Aircrafts database");
        }

        // Update Flight assigned aircraftID
        try {
            // Update flight's aircraftID if assigned
            if (!stdassignedFlight.empty()) {
                for (auto& f : flights["flights"]) {
                    if (f.contains("flightNumber") && f["flightNumber"].is_string() &&
                        f["flightNumber"].get<std::string>() == stdassignedFlight) {
                        f["aircraftID"] = stdaircraftID;
                        break;
                    }
                }

                if (!writeToDP(flightDP, flights)) {
                    throw std::runtime_error("Aircraft added but failed to update flight assignment");
                }

            }
        } catch (const std::exception& e) {
            qDebug() << "Warning: Failed to update Flight aircraftID:" << e.what();
            throw std::runtime_error("Failed to update Flight aircraftID");
        }

        QMessageBox::information(this, "Success", "The Aircraft added successfully");

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to add Aircraft: %1").arg(e.what()));
        qDebug() << "Error details:" << e.what();
    }

}


void adminMangeAircraft::on_searchOnAircraftToUpdate_clicked()
{
    try {
        // Read flight data from database
        json aircrafts = readFromDP(AirCraftDB);

        // Check if there are any flights
        if (aircrafts["aircraft"].empty()) {
            QMessageBox::information(this, "No Aircrafts", "The Aircraft database is empty.");
            return;
        }

        currentAircraftID = ui->updateAircraftIDlineEdit->text().trimmed().toUpper();

        bool aircraftFound = false;

        // Search for the flight
        for (auto& aircraft : aircrafts["aircraft"]) {
            std::string aircraftID = aircraft["aircraftID"];
            if (QString::fromStdString(aircraftID).toUpper() == currentAircraftID) {
                aircraftFound = true;

                // Helper function to safely get JSON values
                auto getValue = [&aircraft](const char* key) -> QString {
                    if (aircraft.contains(key)) {
                        auto value = aircraft[key];
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
                ui->updateAircraftModellineEdit->setText(getValue("model"));
                ui->updateAircraftAssignedFlightlineEdit->setText(getValue("assignedFlight"));
                ui->updateAircraftAvalineEdit->setText(getValue("availability"));
                ui->updateAircraftMainSchelineEdit->setText(getValue("maintenanceSchedule"));

            }
        }

        if (!aircraftFound) {
            QMessageBox::warning(this, "Not Found",
                                 QString("Aircraft %1 not found in database.").arg(currentAircraftID));
        }

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to search for Aircraft: %1").arg(e.what()));
        qDebug() << "Error details:" << e.what();
    }
}

void adminMangeAircraft::on_updateAircraftBtn_clicked()
{
    // Read existing data from files
    json flights = readFromDP(flightDP);
    json aircrafts = readFromDP(AirCraftDB);

    if (aircrafts["aircraft"].empty()) {
        QMessageBox::information(this, "No Aircraft", "The aircraft database is empty.");
        return;
    }

    // Get input values from UI
    currentAircraftID = ui->updateAircraftIDlineEdit->text().trimmed().toUpper();
    assignedFlight = ui->updateAircraftAssignedFlightlineEdit->text().trimmed().toUpper();
    availability = ui->updateAircraftAvalineEdit->text().trimmed();
    maintenanceSchedule = ui->updateAircraftMainSchelineEdit->text().trimmed();
    model = ui->updateAircraftModellineEdit->text().trimmed();

    // Find the aircraft to update
    int aircraftIndex = isAircraftExist(aircrafts, currentAircraftID.toStdString());

    if (aircraftIndex == -1) {
        QMessageBox::information(this, "Error", "This Aircraft ID does not exist");
        return;
    }

    json &aircraft = aircrafts["aircraft"][aircraftIndex];

    // Get the old assigned flight before updating
    QString oldAssignedFlight = QString::fromStdString(aircraft["assignedFlight"]);

    // Validate inputs
    if (currentAircraftID.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter an Aircraft ID");
        return;
    }
    else if (assignedFlight.isEmpty() && availability == "0") {
        QMessageBox::warning(this, "Error", "You can't make the Aircraft Unavailable without assigning a Flight");
        return;
    }
    else if (!assignedFlight.isEmpty() && availability == "1") {
        QMessageBox::warning(this, "Error", "You can't make the Aircraft Available while assigning a Flight");
        return;
    }
    else if (availability.isEmpty() || (availability != "0" && availability != "1")) {
        QMessageBox::warning(this, "Error", "Please enter the Aircraft status: 0 For False and 1 For True");
        return;
    }
    else if (model.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter an Aircraft Model");
        return;
    }
    else if (maintenanceSchedule.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a Maintenance Schedule");
        return;
    }

    bool avaState = (availability == "1");

    // Check if assigned flight exists and isn't already assigned to another aircraft
    if (!assignedFlight.isEmpty()) {
        int flightIndex = isFlightExists(flights, assignedFlight.toStdString());
        if (flightIndex == -1) {
            QMessageBox::warning(this, "Error", "Assigned flight doesn't exist");
            return;
        }

        // Check if flight is already assigned to another aircraft
        std::string currentAssignedAircraft = flights["flights"][flightIndex]["aircraftID"];
        if (!currentAssignedAircraft.empty() && currentAssignedAircraft != currentAircraftID.toStdString()) {
            QMessageBox::warning(this, "Error", "Flight is already assigned to another aircraft");
            return;
        }
    }

    // Update aircraft information
    aircraft["model"] = model.toStdString();
    aircraft["maintenanceSchedule"] = maintenanceSchedule.toStdString();
    aircraft["availability"] = avaState;

    // Handle flight assignment changes
    if (oldAssignedFlight != assignedFlight) {
        // Remove assignment from old flight if it exists
        if (!oldAssignedFlight.isEmpty()) {
            int oldFlightIndex = isFlightExists(flights, oldAssignedFlight.toStdString());
            if (oldFlightIndex != -1) {
                flights["flights"][oldFlightIndex]["aircraftID"] = "";
            }
        }

        // Assign to new flight if specified
        if (!assignedFlight.isEmpty()) {
            int newFlightIndex = isFlightExists(flights, assignedFlight.toStdString());
            flights["flights"][newFlightIndex]["aircraftID"] = currentAircraftID.toStdString();
            aircraft["assignedFlight"] = assignedFlight.toStdString();
        } else {
            aircraft["assignedFlight"] = "";
        }
    }

    // Write updates to both databases
    if (!writeToDP(AirCraftDB, aircrafts)) {
        QMessageBox::critical(this, "Error", "Failed to update aircraft in database");
        return;
    }

    if (!writeToDP(flightDP, flights)) {
        QMessageBox::critical(this, "Error", "Aircraft updated but failed to update flight assignments");
        return;
    }

    QMessageBox::information(this, "Success", "Aircraft updated successfully");

    // Clear the form fields
    ui->updateAircraftIDlineEdit->clear();
    ui->updateAircraftAssignedFlightlineEdit->clear();
    ui->updateAircraftAvalineEdit->clear();
    ui->updateAircraftMainSchelineEdit->clear();
    ui->updateAircraftModellineEdit->clear();

}


void adminMangeAircraft::on_removeAircraftBtn_clicked()
{
    try {
        // Read databases
        json aircrafts = readFromDP(AirCraftDB);
        json flights = readFromDP(flightDP);

        if (aircrafts["aircraft"].empty()) {
            QMessageBox::information(this, "No Aircrafts", "The aircraft database is empty.");
            return;
        }

        QString aircraftID = ui->removeAircraftIDlineEdit->text().trimmed().toUpper();
        bool aircraftFound = false;
        std::string assignedFlight;

        // Find and remove the aircraft
        auto& aircraftArray = aircrafts["aircraft"];
        for (auto it = aircraftArray.begin(); it != aircraftArray.end(); ++it) {
            if ((*it)["aircraftID"] == aircraftID.toStdString()) {
                aircraftFound = true;

                // Get assigned flight before removal
                if ((*it).contains("assignedFlight")) {
                    assignedFlight = (*it)["assignedFlight"];
                }

                // Remove the aircraft
                aircraftArray.erase(it);
                break;
            }
        }

        if (!aircraftFound) {
            QMessageBox::warning(this, "Not Found",
                                 QString("Aircraft %1 not found in database.").arg(aircraftID));
            return;
        }

        // If aircraft was assigned to a flight, clear the assignment
        if (!assignedFlight.empty()) {
            bool flightFound = false;

            // Find and update the assigned flight
            for (auto& flight : flights["flights"]) {
                if (flight["flightNumber"] == assignedFlight) {
                    flightFound = true;
                    flight["aircraftID"] = ""; // Clear the assignment
                    break;
                }
            }

            if (!flightFound) {
                qDebug() << "Assigned flight" << QString::fromStdString(assignedFlight)
                << "not found in flight database";
            }
        }

        // Write updated data back to files
        if (!writeToDP(AirCraftDB, aircrafts)) {
            throw std::runtime_error("Failed to update aircraft database");
        }

        if (!assignedFlight.empty() && !writeToDP(flightDP, flights)) {
            throw std::runtime_error("Aircraft removed but failed to update flight database");
        }

        QMessageBox::information(this, "Success",
                                 QString("Aircraft %1 removed successfully").arg(aircraftID));

        // Clear the UI fields
        ui->removeAircraftIDlineEdit->clear();

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to remove aircraft: %1").arg(e.what()));
        qDebug() << "Error details:" << e.what();
    }
}


void adminMangeAircraft::on_assignAircraftBtn_clicked()
{
    try {
        // Get input values
        QString aircraftID = ui->assignAircraftIDlineEdit->text().trimmed().toUpper();
        QString flightNumber = ui->assignAircraftAssignedFlightlineEdit->text().trimmed().toUpper();

        // Validate inputs
        if (aircraftID.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please enter an Aircraft ID");
            return;
        }
        if (flightNumber.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please enter a Flight Number");
            return;
        }

        // Read databases
        json aircrafts = readFromDP(AirCraftDB);
        json flights = readFromDP(flightDP);

        // Find the aircraft
        int aircraftIndex = -1;
        std::string oldAssignedFlight;
        for (size_t i = 0; i < aircrafts["aircraft"].size(); i++) {
            if (aircrafts["aircraft"][i]["aircraftID"] == aircraftID.toStdString()) {
                aircraftIndex = i;
                if (aircrafts["aircraft"][i].contains("assignedFlight")) {
                    oldAssignedFlight = aircrafts["aircraft"][i]["assignedFlight"];
                }
                break;
            }
        }

        if (aircraftIndex == -1) {
            QMessageBox::warning(this, "Error", "Aircraft not found");
            return;
        }

        // Find the new flight
        int flightIndex = -1;
        QString newFlightDate;
        for (size_t i = 0; i < flights["flights"].size(); i++) {
            if (flights["flights"][i]["flightNumber"] == flightNumber.toStdString()) {
                flightIndex = i;
                newFlightDate = QString::fromStdString(flights["flights"][i]["departureTime"].get<std::string>()).left(10); // Extract YYYY-MM-DD
                break;
            }
        }

        if (flightIndex == -1) {
            QMessageBox::warning(this, "Error", "Flight not found");
            return;
        }

        // Check if flight is already assigned to another aircraft
        std::string currentAssignedAircraft = flights["flights"][flightIndex]["aircraftID"];
        if (!currentAssignedAircraft.empty() && currentAssignedAircraft != aircraftID.toStdString()) {
            QMessageBox::warning(this, "Error", "Flight is already assigned to another aircraft");
            return;
        }

        // Check if aircraft is already assigned to another flight
        if (!oldAssignedFlight.empty() && oldAssignedFlight != flightNumber.toStdString()) {
            QMessageBox::warning(this, "Error",
                                 QString("Aircraft is already assigned to flight %1. "
                                         "Please remove the current assignment first.")
                                     .arg(QString::fromStdString(oldAssignedFlight)));
            return;
        }


        // Update aircraft record
        aircrafts["aircraft"][aircraftIndex]["assignedFlight"] = flightNumber.toStdString();
        aircrafts["aircraft"][aircraftIndex]["availability"] = false;

        // Update flight record
        flights["flights"][flightIndex]["aircraftID"] = aircraftID.toStdString();

        // If aircraft was previously assigned to a different flight, clear that assignment
        if (!oldAssignedFlight.empty() && oldAssignedFlight != flightNumber.toStdString()) {
            for (auto& flight : flights["flights"]) {
                if (flight["flightNumber"] == oldAssignedFlight) {
                    flight["aircraftID"] = "";
                    break;
                }
            }
        }

        // Write changes to databases
        if (!writeToDP(AirCraftDB, aircrafts)) {
            throw std::runtime_error("Failed to update aircraft database");
        }

        if (!writeToDP(flightDP, flights)) {
            throw std::runtime_error("Failed to update flight database");
        }

        QMessageBox::information(this, "Success",
                                 QString("Aircraft %1 successfully assigned to flight %2")
                                     .arg(aircraftID)
                                     .arg(flightNumber));

        // Clear input fields
        ui->assignAircraftIDlineEdit->clear();
        ui->assignAircraftAssignedFlightlineEdit->clear();

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to assign aircraft: %1").arg(e.what()));
        qDebug() << "Error details:" << e.what();
    }
}


void adminMangeAircraft::on_maintenanceBtn_clicked()
{
    try {
        // Get input values
        QString aircraftID = ui->scheduleAircraftIDlineEdit->text().trimmed().toUpper();
        QString maintenanceSchedule = ui->scheduleAircraftMainSchelineEdit->text().trimmed();

        // Validate inputs
        if (aircraftID.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please enter an Aircraft ID");
            return;
        }
        if (maintenanceSchedule.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please enter a Maintenance Schedule");
            return;
        }

        // Validate date format
        QRegularExpression dateRegex("^\\d{2}-\\d{2}-\\d{4}$");
        if (!dateRegex.match(maintenanceSchedule).hasMatch()) {
            QMessageBox::warning(this, "Error", "Please enter date in DD-MM-YYYY format");
            return;
        }

        // Read databases
        json aircrafts = readFromDP(AirCraftDB);
        json flights = readFromDP(flightDP);

        bool aircraftFound = false;
        bool wasAssignedToFlight = false;
        std::string assignedFlight;

        // Find and update the aircraft
        for (auto& aircraft : aircrafts["aircraft"]) {
            if (aircraft["aircraftID"] == aircraftID.toStdString()) {
                aircraftFound = true;

                // Check and store current assignment
                if (aircraft.contains("assignedFlight") && !aircraft["assignedFlight"].empty()) {
                    wasAssignedToFlight = true;
                    assignedFlight = aircraft["assignedFlight"];
                    // Clear the assigned flight from aircraft record
                    aircraft["assignedFlight"] = "";
                }

                // Update maintenance info
                aircraft["maintenanceSchedule"] = maintenanceSchedule.toStdString();
                aircraft["availability"] = false; // Set as unavailable
                break;
            }
        }

        if (!aircraftFound) {
            QMessageBox::warning(this, "Error", QString("Aircraft %1 not found").arg(aircraftID));
            return;
        }

        // Update flight database if needed
        if (wasAssignedToFlight) {
            for (auto& flight : flights["flights"]) {
                if (flight["flightNumber"] == assignedFlight) {
                    flight["aircraftID"] = ""; // Clear aircraft assignment
                    break;
                }
            }
        }

        // Write changes to both databases
        if (!writeToDP(AirCraftDB, aircrafts)) {
            throw std::runtime_error("Failed to update aircraft database");
        }

        if (wasAssignedToFlight && !writeToDP(flightDP, flights)) {
            throw std::runtime_error("Failed to update flight database");
        }

        // Prepare success message
        QString message = QString("Maintenance scheduled for aircraft %1 on %2\n"
                                  "Status: Unavailable for maintenance")
                              .arg(aircraftID).arg(maintenanceSchedule);

        if (wasAssignedToFlight) {
            message += QString("\n\nNote: Removed assignment from flight %1")
            .arg(QString::fromStdString(assignedFlight));
        }

        QMessageBox::information(this, "Success", message);

        // Clear UI fields
        ui->scheduleAircraftIDlineEdit->clear();
        ui->scheduleAircraftMainSchelineEdit->clear();

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to schedule maintenance: %1").arg(e.what()));
        qDebug() << "Error details:" << e.what();
    }
}

void adminMangeAircraft::on_availabilityBtn_clicked()
{
    try {
        // Get aircraft ID from input
        QString aircraftID = ui->checkAvaAircraftIDlineEdit->text().trimmed().toUpper();

        if (aircraftID.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please enter an Aircraft ID");
            return;
        }

        // Read aircraft database
        json aircrafts = readFromDP(AirCraftDB);

        bool aircraftFound = false;
        bool isAvailable = false;
        QString assignedFlight = "None";
        QString maintenanceStatus;

        // Search for the aircraft
        for (const auto& aircraft : aircrafts["aircraft"]) {
            if (aircraft["aircraftID"] == aircraftID.toStdString()) {
                aircraftFound = true;

                // Get availability status
                isAvailable = aircraft["availability"];

                // Get assigned flight if exists
                if (aircraft.contains("assignedFlight") && !aircraft["assignedFlight"].empty()) {
                    assignedFlight = QString::fromStdString(aircraft["assignedFlight"]);
                }

                // Get maintenance schedule
                if (aircraft.contains("maintenanceSchedule")) {
                    maintenanceStatus = QString::fromStdString(aircraft["maintenanceSchedule"]);
                }
                break;
            }
        }

        if (!aircraftFound) {
            QMessageBox::warning(this, "Not Found",
                                 QString("Aircraft %1 not found in database.").arg(aircraftID));
            return;
        }

        // Prepare status message
        QString statusMessage = QString("Aircraft %1\n\n").arg(aircraftID);
        statusMessage += QString("Availability: %1\n").arg(isAvailable ? "Available" : "Unavailable");
        statusMessage += QString("Assigned Flight: %1\n").arg(assignedFlight);
        statusMessage += QString("Maintenance Schedule: %1").arg(maintenanceStatus);

        // Check if aircraft is available for assignment
        if (isAvailable && assignedFlight == "") {
            statusMessage += "\n\nStatus: This aircraft is ready for flight assignment";
        } else if (!isAvailable && assignedFlight != "") {
            statusMessage += "\n\nStatus: Currently assigned to a flight";
        } else if (!isAvailable && assignedFlight == "") {
            statusMessage += "\n\nStatus: Unavailable but not assigned (may need maintenance)";
        } else {
            statusMessage += "\n\nStatus: Available but shows flight assignment (data inconsistency)";
        }

        QMessageBox::information(this, "Aircraft Availability", statusMessage);

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error",
                              QString("Failed to check aircraft availability: %1").arg(e.what()));
        qDebug() << "Error details:" << e.what();
    }
}

void adminMangeAircraft::viewAllAirCrafts()
{
    // Load from file (or your actual data source)
    QFile jsonFile("../../data/aircraft.json");  // Adjust path as needed
    if (!jsonFile.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Could not open aircraft data file");
        return;
    }

    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (doc.isNull() || !doc.isObject()) {
        QMessageBox::warning(this, "Error", "Invalid aircrafts data format");
        return;
    }

    QJsonObject jsonObj = doc.object();
    QJsonArray aircraftsArray = jsonObj["aircraft"].toArray();

    QTableWidget* table = ui->viewAircraftTableWidget;

    table->clearContents();
    table->setRowCount(0);
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels({"Aircraft ID", "Availability", "Model", "Maintenance Schedule", "Assigned Flight"});

    table->setRowCount(aircraftsArray.size());
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int row = 0; row < aircraftsArray.size(); ++row) {
        QJsonObject aircraft = aircraftsArray[row].toObject();

        // Create items with centered alignment
        QTableWidgetItem* aircraftNoItem = new QTableWidgetItem(aircraft["aircraftID"].toString());
        QTableWidgetItem* assignedFlightItem = new QTableWidgetItem(aircraft["assignedFlight"].toString());
        QTableWidgetItem* availabilityItem = new QTableWidgetItem(aircraft["availability"].toBool() ? "Available" : "Unavailable");
        QTableWidgetItem* maintenanceScheduleItem = new QTableWidgetItem(aircraft["maintenanceSchedule"].toString());
        QTableWidgetItem* modelItem = new QTableWidgetItem(aircraft["model"].toString());

        // Set center alignment for all items
        aircraftNoItem->setTextAlignment(Qt::AlignCenter);
        assignedFlightItem->setTextAlignment(Qt::AlignCenter);
        availabilityItem->setTextAlignment(Qt::AlignCenter);
        maintenanceScheduleItem->setTextAlignment(Qt::AlignCenter);
        modelItem->setTextAlignment(Qt::AlignCenter);

        // Set items in table
        table->setItem(row, 0, aircraftNoItem);
        table->setItem(row, 1, availabilityItem);
        table->setItem(row, 2, modelItem);
        table->setItem(row, 3, maintenanceScheduleItem);
        table->setItem(row, 4, assignedFlightItem);

        table->resizeColumnsToContents();
        table->horizontalHeader()->setStretchLastSection(true);

    }

}

adminMangeAircraft::~adminMangeAircraft()
{
    delete ui;
}


