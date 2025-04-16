#include "_2a3adminmangeusers.h"
#include "ui__2a3adminmangeusers.h"

adminMangeUsers::adminMangeUsers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminMangeUsers)
{
    ui->setupUi(this);
    connect(ui->userTabWidget, &QTabWidget::currentChanged,
            this, [this](int index) {
                if (ui->userTabWidget->widget(index) == ui->viewUsersTab) {
                    viewAllUsers(); // Call your slot
                }
            });
    setWindowTitle("Admin Dashboard - Mange Users");

}

void adminMangeUsers::on_newAdminBtn_clicked()
{
    QString username = ui->addAdminUsernameLineEdit->text().trimmed();
    QString password = ui->addAdminPassLineEdit->text().trimmed();
    QString userID = ui->addAdminUserIDLineEdit->text().trimmed();

    if(username.isEmpty() || password.isEmpty() || userID.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill all fields");
        return;
    }

    json users = readFromDP(UserDP);

    // Check if username already exists
    for(const auto& user : users["users"]) {
        if(user["username"] == username.toStdString()) {
            QMessageBox::warning(this, "Error", "Username already exists");
            return;
        }
    }

    // Check if userID already exists
    for(const auto& user : users["users"]) {
        if(user["userID"] == userID.toStdString()) {
            QMessageBox::warning(this, "Error", "User ID already exists");
            return;
        }
    }

    // Create new admin
    json newAdmin = {
        {"username", username.toStdString()},
        {"password", password.toStdString()},
        {"role", "ADMIN"},
        {"userID", userID.toStdString()}
    };

    users["users"].push_back(newAdmin);
    writeToDP(UserDP, users);

    // Clear input fields
    ui->addAdminUsernameLineEdit->clear();
    ui->addAdminPassLineEdit->clear();
    ui->addAdminUserIDLineEdit->clear();

    QMessageBox::information(this, "Success", "New admin added successfully");
}



void adminMangeUsers::on_newBookingAgentBtn_clicked()
{
    QString username = ui->addBookingAgentUsernameLineEdit->text().trimmed();
    QString password = ui->addBookingAgentPassLineEdit->text().trimmed();
    QString userID = ui->addBookingAgentUserIDLineEdit->text().trimmed();

    if(username.isEmpty() || password.isEmpty() || userID.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill all fields");
        return;
    }

    json users = readFromDP(UserDP);

    // Check if username already exists
    for(const auto& user : users["users"]) {
        if(user["username"] == username.toStdString()) {
            QMessageBox::warning(this, "Error", "Username already exists");
            return;
        }
    }

    // Check if userID already exists
    for(const auto& user : users["users"]) {
        if(user["userID"] == userID.toStdString()) {
            QMessageBox::warning(this, "Error", "User ID already exists");
            return;
        }
    }

    // Create new booking agent
    json newAgent = {
        {"username", username.toStdString()},
        {"password", password.toStdString()},
        {"role", "BOOKING_AGENT"},
        {"userID", userID.toStdString()}
    };

    users["users"].push_back(newAgent);
    writeToDP(UserDP, users);

    // Clear input fields
    ui->addBookingAgentUsernameLineEdit->clear();
    ui->addBookingAgentPassLineEdit->clear();
    ui->addBookingAgentUserIDLineEdit->clear();

    QMessageBox::information(this, "Success", "New booking agent added successfully");
}

void adminMangeUsers::on_newPassengerBtn_clicked()
{
    // Get basic info
    QString username = ui->addPassengerUsernameLineEdit->text().trimmed();
    QString password = ui->addPassengerPassLineEdit->text().trimmed();
    QString userID = ui->addPassengerUserIDLineEdit->text().trimmed();
    QString contactInfo = ui->addPassengerContactInfoLineEdit->text().trimmed();
    QString loyaltyPoints = ui->addPassengerLoyaltyPointsLineEdit->text().trimmed();
    QString wallet = ui->addPassengerWalletLineEdit->text().trimmed();

    // Get payment info
    QString cardNumber = ui->addPassengerCCCNLineEdit->text().trimmed();
    QString expiryDate = ui->addPassengerCCEDLineEdit->text().trimmed();
    QString cvv = ui->addPassengerCCCCVLineEdit->text().trimmed();
    QString paypalAccount = ui->addPassengerPaypadLineEdit->text().trimmed();

    // Validate required fields
    if(username.isEmpty() || password.isEmpty() || userID.isEmpty() ||
        contactInfo.isEmpty() || loyaltyPoints.isEmpty() || wallet.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill all required fields");
        return;
    }

    // Validate numeric fields
    bool ok;
    int loyaltyPointsInt = loyaltyPoints.toInt(&ok);
    if(!ok) {
        QMessageBox::warning(this, "Warning", "Loyalty points must be a number");
        return;
    }

    double walletDouble = wallet.toDouble(&ok);
    if(!ok) {
        QMessageBox::warning(this, "Warning", "Wallet balance must be a number");
        return;
    }

    json users = readFromDP(UserDP);

    // Check if username already exists
    for(const auto& user : users["users"]) {
        if(user["username"] == username.toStdString()) {
            QMessageBox::warning(this, "Error", "Username already exists");
            return;
        }
    }

    // Check if userID already exists
    for(const auto& user : users["users"]) {
        if(user["userID"] == userID.toStdString()) {
            QMessageBox::warning(this, "Error", "User ID already exists");
            return;
        }
    }

    // Create new passenger
    json newPassenger = {
        {"username", username.toStdString()},
        {"password", password.toStdString()},
        {"role", "PASSENGER"},
        {"userID", userID.toStdString()},
        {"contactInfo", contactInfo.toStdString()},
        {"loyaltyPoints", loyaltyPointsInt},
        {"wallet", walletDouble},
        {"creditCard", {
                           {"cardNumber", cardNumber.toStdString()},
                           {"expiryDate", expiryDate.toStdString()},
                           {"cvv", cvv.toStdString()}
                       }},
        {"paypalAccount", paypalAccount.toStdString()}
    };

    users["users"].push_back(newPassenger);
    writeToDP(UserDP, users);

    // Clear all input fields
    ui->addPassengerUsernameLineEdit->clear();
    ui->addPassengerPassLineEdit->clear();
    ui->addPassengerUserIDLineEdit->clear();
    ui->addPassengerContactInfoLineEdit->clear();
    ui->addPassengerLoyaltyPointsLineEdit->clear();
    ui->addPassengerWalletLineEdit->clear();
    ui->addPassengerCCCNLineEdit->clear();
    ui->addPassengerCCEDLineEdit->clear();
    ui->addPassengerCCCCVLineEdit->clear();
    ui->addPassengerPaypadLineEdit->clear();

    QMessageBox::information(this, "Success", "New passenger added successfully");
}



void adminMangeUsers::on_updateSearchOnAdminUsername_clicked()
{
    QString username = ui->updateAdminUsernameLineEdit->text();
    if(username.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a username to search");
        return;
    }

    json users = readFromDP(UserDP);
    for(const auto& user : users["users"]) {
        if(user["role"] == "ADMIN" && user["username"] == username.toStdString()) {
            ui->updateAdminUserIDLineEdit->setText(QString::fromStdString(user["userID"]));
            return;
        }
    }

    QMessageBox::information(this, "Not Found", "Admin username not found");
}

void adminMangeUsers::on_updateAdminBtn_clicked()
{
    QString username = ui->updateAdminUsernameLineEdit->text();
    QString newUserID = ui->updateAdminUserIDLineEdit->text();

    if(username.isEmpty() || newUserID.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill all fields");
        return;
    }

    json users = readFromDP(UserDP);
    bool found = false;
    bool idExists = false;

    // First check if the new userID exists for any other user
    for(const auto& user : users["users"]) {
        if(user["userID"] == newUserID.toStdString() && user["username"] != username.toStdString()) {
            idExists = true;
            break;
        }
    }

    if(idExists) {
        QMessageBox::warning(this, "Error", "This User ID is already assigned to another user");
        return;
    }

    // If userID is available, proceed with update
    for(auto& user : users["users"]) {
        if(user["role"] == "ADMIN" && user["username"] == username.toStdString()) {
            user["userID"] = newUserID.toStdString();
            found = true;
            break;
        }
    }

    if(found) {
        writeToDP(UserDP, users);
        QMessageBox::information(this, "Success", "Admin information updated");
        ui->updateAdminUsernameLineEdit->clear();
        ui->updateAdminUserIDLineEdit->clear();
    } else {
        QMessageBox::warning(this, "Error", "Admin not found");
    }
}

void adminMangeUsers::on_updateSearchOnBookingAgentUsername_clicked()
{
    QString username = ui->updateBookingAgentUsernameLineEdit->text();
    if(username.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a username to search");
        return;
    }

    json users = readFromDP(UserDP);
    for(const auto& user : users["users"]) {
        if(user["role"] == "BOOKING_AGENT" && user["username"] == username.toStdString()) {
            ui->updateBookingAgentUserIDLineEdit->setText(QString::fromStdString(user["userID"]));
            return;
        }
    }

    QMessageBox::information(this, "Not Found", "Booking Agent username not found");
}


void adminMangeUsers::on_updateBookingAgentBtn_clicked()
{
    QString username = ui->updateBookingAgentUsernameLineEdit->text();
    QString newUserID = ui->updateBookingAgentUserIDLineEdit->text();

    if(username.isEmpty() || newUserID.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill all fields");
        return;
    }

    json users = readFromDP(UserDP);
    bool found = false;
    bool idExists = false;

    // First check if the new userID exists for any other user
    for(const auto& user : users["users"]) {
        if(user["userID"] == newUserID.toStdString() && user["username"] != username.toStdString()) {
            idExists = true;
            break;
        }
    }

    if(idExists) {
        QMessageBox::warning(this, "Error", "This User ID is already assigned to another user");
        return;
    }

    // If userID is available, proceed with update
    for(auto& user : users["users"]) {
        if(user["role"] == "BOOKING_AGENT" && user["username"] == username.toStdString()) {
            user["userID"] = newUserID.toStdString();
            found = true;
            break;
        }
    }

    if(found) {
        writeToDP(UserDP, users);
        QMessageBox::information(this, "Success", "Booking Agent information updated");
        ui->updateBookingAgentUsernameLineEdit->clear();
        ui->updateBookingAgentUserIDLineEdit->clear();
    } else {
        QMessageBox::warning(this, "Error", "Booking Agent not found");
    }
}


void adminMangeUsers::on_updateSearchOnPassengerUsername_clicked()
{
    QString username = ui->updatePassengerUsernameLineEdit->text();
    if(username.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a username to search");
        return;
    }

    json users = readFromDP(UserDP);
    for(const auto& user : users["users"]) {
        if(user["role"] == "PASSENGER" && user["username"] == username.toStdString()) {
            ui->updatePassengerUserIDLineEdit->setText(QString::fromStdString(user["userID"]));
            ui->updatePassengerPassLineEdit->setText(QString::fromStdString(user["password"]));
            ui->updatePassengerContactInfoLineEdit->setText(QString::fromStdString(user["contactInfo"]));
            ui->updatePassengerLoyaltyPointsLineEdit->setText(QString::number(user["loyaltyPoints"].get<int>()));
            ui->updatePassengerWalletLineEdit->setText(QString::number(user["wallet"].get<double>()));

            // Credit card info
            auto creditCard = user["creditCard"];
            ui->updatePassengerCCCNLineEdit->setText(QString::fromStdString(creditCard["cardNumber"]));
            ui->updatePassengerCCEDLineEdit->setText(QString::fromStdString(creditCard["expiryDate"]));
            ui->updatePassengerCCCCVLineEdit->setText(QString::fromStdString(creditCard["cvv"]));

            // PayPal
            ui->updatePassengerPaypadLineEdit->setText(QString::fromStdString(user["paypalAccount"]));
            return;
        }
    }

    QMessageBox::information(this, "Not Found", "Passenger username not found");
}


void adminMangeUsers::on_updatePassengerBtn_clicked()
{
    QString username = ui->updatePassengerUsernameLineEdit->text();
    QString newUserID = ui->updatePassengerUserIDLineEdit->text();

    if(username.isEmpty() || newUserID.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Username and User ID are required");
        return;
    }

    json users = readFromDP(UserDP);
    bool found = false;
    bool idExists = false;

    // First check if the new userID exists for any other user
    for(const auto& user : users["users"]) {
        if(user["userID"] == newUserID.toStdString() && user["username"] != username.toStdString()) {
            idExists = true;
            break;
        }
    }

    if(idExists) {
        QMessageBox::warning(this, "Error", "This User ID is already assigned to another user");
        return;
    }

    // If userID is available, proceed with update
    for(auto& user : users["users"]) {
        if(user["role"] == "PASSENGER" && user["username"] == username.toStdString()) {
            // Update all fields
            user["userID"] = newUserID.toStdString();
            user["password"] = ui->updatePassengerPassLineEdit->text().toStdString();
            user["contactInfo"] = ui->updatePassengerContactInfoLineEdit->text().toStdString();
            user["loyaltyPoints"] = ui->updatePassengerLoyaltyPointsLineEdit->text().toInt();
            user["wallet"] = ui->updatePassengerWalletLineEdit->text().toDouble();

            // Update credit card
            user["creditCard"]["cardNumber"] = ui->updatePassengerCCCNLineEdit->text().toStdString();
            user["creditCard"]["expiryDate"] = ui->updatePassengerCCEDLineEdit->text().toStdString();
            user["creditCard"]["cvv"] = ui->updatePassengerCCCCVLineEdit->text().toStdString();

            // Update PayPal
            user["paypalAccount"] = ui->updatePassengerPaypadLineEdit->text().toStdString();

            found = true;
            break;
        }
    }

    if(found) {
        writeToDP(UserDP, users);
        QMessageBox::information(this, "Success", "Passenger information updated");
        ui->updatePassengerUsernameLineEdit->clear();
        ui->updatePassengerUserIDLineEdit->clear();
        ui->updatePassengerCCCCVLineEdit->clear();
        ui->updatePassengerCCCNLineEdit->clear();
        ui->updatePassengerCCEDLineEdit->clear();
        ui->updatePassengerContactInfoLineEdit->clear();
        ui->updatePassengerLoyaltyPointsLineEdit->clear();
        ui->updatePassengerPassLineEdit->clear();
        ui->updatePassengerPaypadLineEdit->clear();

    } else {
        QMessageBox::warning(this, "Error", "Passenger not found");
    }
}

void adminMangeUsers::on_deleteUserBtn_clicked()
{
    QString userID = ui->DeleteUserLineEdit->text();
    if(userID.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a User ID to delete");
        return;
    }

    json users = readFromDP(UserDP);
    bool found = false;

    for(auto it = users["users"].begin(); it != users["users"].end(); ++it) {
        if((*it)["userID"] == userID.toStdString()) {
            users["users"].erase(it);
            found = true;
            break;
        }
    }

    if(found) {
        writeToDP(UserDP, users);
        QMessageBox::information(this, "Success", "User deleted successfully");
        ui->DeleteUserLineEdit->clear();

    } else {
        QMessageBox::warning(this, "Error", "User ID not found");
    }
}



void adminMangeUsers::on_searchForUserBtn_clicked()
{
    QString userID = ui->SearchUserlineEdit->text();
    if(userID.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter a User ID to search");
        return;
    }

    json users = readFromDP(UserDP);
    for(const auto& user : users["users"]) {
        if(user["userID"] == userID.toStdString()) {
            QString role = QString::fromStdString(user["role"]);
            QString message;

            if(role == "PASSENGER") {
                // Display all 9 fields for passengers
                message = QString("User Found (Passenger):\n"
                                  "Username: %1\n"
                                  "Password: %2\n"
                                  "User ID: %3\n"
                                  "Contact Info: %4\n"
                                  "Loyalty Points: %5\n"
                                  "Wallet Balance: %6\n"
                                  "Credit Card:\n"
                                  "  - Number: %7\n"
                                  "  - Expiry: %8\n"
                                  "  - CVV: %9\n"
                                  "PayPal Account: %10")
                              .arg(QString::fromStdString(user["username"]))
                              .arg(QString::fromStdString(user["password"]))
                              .arg(QString::fromStdString(user["userID"]))
                              .arg(QString::fromStdString(user["contactInfo"]))
                              .arg(QString::number(user["loyaltyPoints"].get<int>()))
                              .arg(QString::number(user["wallet"].get<double>(), 'f', 2))
                              .arg(QString::fromStdString(user["creditCard"]["cardNumber"]))
                              .arg(QString::fromStdString(user["creditCard"]["expiryDate"]))
                              .arg(QString::fromStdString(user["creditCard"]["cvv"]))
                              .arg(QString::fromStdString(user["paypalAccount"]));
            } else {
                // Display basic info for non-passengers (Admin/Booking Agent)
                message = QString("User Found (%1):\n"
                                  "Username: %2\n"
                                  "User ID: %3")
                              .arg(role)
                              .arg(QString::fromStdString(user["username"]))
                              .arg(QString::fromStdString(user["userID"]));
            }

            QMessageBox::information(this, "User Found", message);
            ui->SearchUserlineEdit->clear();

            return;
        }
    }

    QMessageBox::information(this, "Not Found", "User ID not found");
}


void  adminMangeUsers::viewAllUsers()
{

    // Clear the table first
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);

    // Set column headers
    QStringList headers;
    headers << "User ID" << "Username" << "Role" << "Contact Info" << "Loyalty Points"
            << "Wallet" << "Credit Card" << "PayPal";
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Read users from database
    json users = readFromDP(UserDP);
    if(users["users"].empty()) {
        QMessageBox::information(this, "Information", "No users found in database");
        return;
    }

    // Populate the table
    for(const auto& user : users["users"]) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Common fields for all users
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(user["userID"])));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(user["username"])));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(user["role"])));

        // Passenger-specific fields
        if(user["role"] == "PASSENGER") {
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(user["contactInfo"])));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(user["loyaltyPoints"].get<int>())));
            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(user["wallet"].get<double>(), 'f', 2)));

            // Format credit card info
            QString ccInfo = QString("%1\nExp: %2\nCVV: %3")
                                 .arg(QString::fromStdString(user["creditCard"]["cardNumber"]))
                                 .arg(QString::fromStdString(user["creditCard"]["expiryDate"]))
                                 .arg(QString::fromStdString(user["creditCard"]["cvv"]));
            ui->tableWidget->setItem(row, 6, new QTableWidgetItem(ccInfo));

            ui->tableWidget->setItem(row, 7, new QTableWidgetItem(QString::fromStdString(user["paypalAccount"])));
        } else {
            // Empty fields for non-passengers
            for(int col = 3; col <= 7; col++) {
                ui->tableWidget->setItem(row, col, new QTableWidgetItem("N/A"));
            }
        }
    }

    // Adjust column widths to content
    ui->tableWidget->resizeColumnsToContents();

    // Enable sorting
    ui->tableWidget->setSortingEnabled(true);

    // Optional: Set alternating row colors for better readability
    ui->tableWidget->setAlternatingRowColors(true);

}

adminMangeUsers::~adminMangeUsers()
{
    delete ui;
}

