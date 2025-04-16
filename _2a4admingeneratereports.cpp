#include "_2a4admingeneratereports.h"
#include "ui__2a4admingeneratereports.h"

std::string Reservs = "../../data/reservation.json";
std::string maintenanceDB = "../../data/maintenance.json";

adminGenerateReports::adminGenerateReports(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminGenerateReports)
{
    ui->setupUi(this);
    setWindowTitle("Admin Dashboard - Report Generation");

}

adminGenerateReports::~adminGenerateReports()
{
    delete ui;
}

void adminGenerateReports::on_generateOperationalBtn_clicked()
{
    QString monthYear = ui->operationalMonthYearEdit->text();
    if (monthYear.length() != 7 || !monthYear.contains("-")) {
        QMessageBox::warning(this, "Invalid Format", "Please enter month and year in MM-YYYY format");
        return;
    }

    // Read data
    json flights = readFromDP(flightDP);
    json reservations = readFromDP(Reservs);

    QString reportText;
    QTextStream stream(&reportText);

    stream << "Operational Report for " << monthYear << "\n\n";
    stream << "Report Summary:\n";

    // Filter and calculate metrics
    int totalFlights = 0, completed = 0, delayed = 0, canceled = 0;
    int totalReservations = 0;
    double totalRevenue = 0.0;

    QString inputMonth = monthYear.left(2);
    QString inputYear = monthYear.mid(3, 4);

    for (const auto& flight : flights["flights"]) {
        QString departureTime = QString::fromStdString(flight["departureTime"]);
        QString flightMonth = departureTime.mid(5, 2);
        QString flightYear = departureTime.left(4);

        if (flightMonth == inputMonth && flightYear == inputYear) {
            totalFlights++;
            QString status = QString::fromStdString(flight["status"]);

            if (status == "ON_TIME" || status == "DELAYED") {
                completed++;
                if (status == "DELAYED") delayed++;
            } else if (status == "CANCELED") {
                canceled++;
            }

            double price = flight["price"].get<double>(); // Extract price as double
            int maxSeats = flight["maxSeats"].get<int>(); // Extract maxSeats as int
            int availableSeats = flight["availableSeats"].get<int>(); // Extract availableSeats as int
            int bookings = maxSeats - availableSeats; // Now subtraction works
            totalReservations += bookings;
            totalRevenue += bookings * price; // Now multiplication works
        }
    }

    // Format report
    stream << "- Total Flights Scheduled: " << totalFlights << "\n";
    stream << "- Flights Completed: " << completed << "\n";
    stream << "- Flights Delayed: " << delayed << "\n";
    stream << "- Flights Canceled: " << canceled << "\n";
    stream << "- Total Reservations: " << totalReservations << "\n";
    stream << QString("- Total Revenue: $%1\n\n").arg(totalRevenue, 0, 'f', 2);

    stream << "Detailed Flight Performance:\n";
    for (const auto& flight : flights["flights"]) {
        QString departureTime = QString::fromStdString(flight["departureTime"]);
        if (departureTime.mid(5, 2) == inputMonth && departureTime.left(4) == inputYear) {
            QString flightNum = QString::fromStdString(flight["flightNumber"]);
            QString status = QString::fromStdString(flight["status"]);
            int maxSeats = flight["maxSeats"].get<int>(); // Extract maxSeats as int
            int availableSeats = flight["availableSeats"].get<int>(); // Extract availableSeats as int
            int bookings = maxSeats - availableSeats; // Now subtraction works
            double price = flight["price"].get<double>(); // Extract price as double
            double revenue = bookings * price; // Now multiplication works

            stream << QString("Flight %1: %2 (%3 bookings, $%4)\n")
                          .arg(flightNum).arg(status).arg(bookings).arg(revenue, 0, 'f', 2);
        }
    }

    ui->operationalReportText->setText(reportText);
}



void adminGenerateReports::on_generateMaintenanceBtn_clicked()
{
    QString monthYear = ui->maintenanceMonthYearEdit->text();
    if(monthYear.length() != 7 || !monthYear.contains("-")) {
        QMessageBox::warning(this, "Invalid Format", "Please enter month and year in MM-YYYY format");
        return;
    }

    json maintenance = readFromDP(maintenanceDB);
    QString reportText;
    QTextStream stream(&reportText);

    stream << "Maintenance Report for " << monthYear << "\n\n";

    QString inputMonth = monthYear.left(2);
    QString inputYear = monthYear.mid(3,4);

    int totalTasks = 0, completed = 0, scheduled = 0, inProgress = 0;

    for(const auto& task : maintenance["maintenance"]) {
        QString taskDate = QString::fromStdString(task["maintenanceDate"]);
        if(taskDate.mid(5,2) == inputMonth && taskDate.left(4) == inputYear) {
            totalTasks++;
            QString status = QString::fromStdString(task["status"]);

            if(status == "COMPLETED") completed++;
            else if(status == "SCHEDULED") scheduled++;
            else if(status == "IN_PROGRESS") inProgress++;
        }
    }

    stream << "Report Summary:\n";
    stream << "- Total Maintenance Tasks: " << totalTasks << "\n";
    stream << "- Tasks Completed: " << completed << "\n";
    stream << "- Tasks Scheduled: " << scheduled << "\n";
    stream << "- Tasks In Progress: " << inProgress << "\n\n";

    stream << "Detailed Maintenance Tasks:\n";
    for(const auto& task : maintenance["maintenance"]) {
        QString taskDate = QString::fromStdString(task["maintenanceDate"]);
        if(taskDate.mid(5,2) == inputMonth && taskDate.left(4) == inputYear) {
            QString id = QString::fromStdString(task["maintenanceID"]);
            QString aircraft = QString::fromStdString(task["aircraftID"]);
            QString desc = QString::fromStdString(task["description"]);
            QString status = QString::fromStdString(task["status"]);

            stream << QString("Task %1: %2 (Aircraft: %3, Status: %4)\n")
                          .arg(id).arg(desc).arg(aircraft).arg(status);
        }
    }

    ui->maintenanceReportText->setText(reportText);
}


void adminGenerateReports::on_generateUserActivityBtn_clicked()
{
    QString monthYear = ui->userActivityMonthYearEdit->text();
    if(monthYear.length() != 7 || !monthYear.contains("-")) {
        QMessageBox::warning(this, "Invalid Format", "Please enter month and year in MM-YYYY format");
        return;
    }

    json users = readFromDP(UserDP);
    json reservations = readFromDP(Reservs);
    QString reportText;
    QTextStream stream(&reportText);

    stream << "User Activity Report for " << monthYear << "\n\n";

    QString inputMonth = monthYear.left(2);
    QString inputYear = monthYear.mid(3,4);

    int activeUsers = 0;
    double totalRevenue = 0.0;

    stream << "User Activity Details:\n";
    for(const auto& user : users["users"]) {
        QString userID = QString::fromStdString(user["userID"]);
        QString username = QString::fromStdString(user["username"]);
        QString role = QString::fromStdString(user["role"]);
        int reservationsCount = 0;

        for(const auto& reservation : reservations["reservations"]) {
            QString resDate = QString::fromStdString(reservation["departureTime"]);
            if(QString::fromStdString(reservation["passengerID"]) == userID &&
                resDate.mid(5,2) == inputMonth && resDate.left(4) == inputYear) {
                reservationsCount++;
                totalRevenue += 250.0; // Fixed price assumption
            }
        }

        if(reservationsCount > 0) {
            activeUsers++;
            stream << QString("%1 (%2): %3 reservations\n")
                          .arg(username).arg(role).arg(reservationsCount);
        }
    }

    stream << "\nReport Summary:\n";
    stream << "- Active Users: " << activeUsers << "\n";
    stream << QString("- Total Revenue: $%1\n").arg(totalRevenue, 0, 'f', 2);

    ui->userActivityReportText->setText(reportText);
}

