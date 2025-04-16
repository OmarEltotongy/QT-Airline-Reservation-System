#ifndef _4_MAINPASSENGERMENU_H
#define _4_MAINPASSENGERMENU_H

#include <QDialog>
#include <QMessageBox>
#include <QStandardItemModel>
#include "jsonHelperFunctions.hpp"
#include <QFile>
#include <QTextStream>
#include <QTableWidget>
#include <QInputDialog>
#include <QRadioButton>

namespace Ui {
class mainPassengerMenu;
}

class mainPassengerMenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainPassengerMenu(QString &username, QWidget *parent = nullptr);
    ~mainPassengerMenu();

private slots:
    void on_searchFlightsBtn_clicked();

    void on_viewReservationsBtn_clicked();

    void on_checkInBtn_clicked();

    void on_BookTheFlightBtn_clicked();
    // New slots for the updated UI
    void selectFlight();
    void clearFlightResults();
    void onFlightDoubleClicked(QTableWidgetItem *item);

private:
    Ui::mainPassengerMenu *ui;
    QString passengerID;

    json readFromJson(const QString &filename);
    bool writeToJson(const QString &filename, const json &data);
    void displayFlights(const json &flights);
    void displayReservations(const json &reservations);
    void showBookingConfirmation(const QString &reservationID, const QString &flightNumber,
                                 const QString &origin, const QString &destination,
                                 const QString &seatNumber, double price);

    QString flightNumber;
    QString origin ;
    QString destination;
    QString currentUsername;

};

#endif // _4_MAINPASSENGERMENU_H
