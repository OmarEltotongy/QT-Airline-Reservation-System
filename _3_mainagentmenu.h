#ifndef _3_MAINAGENTMENU_H
#define _3_MAINAGENTMENU_H

#include <QDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include "jsonHelperFunctions.hpp"

namespace Ui {
class mainAgentMenu;
}

class mainAgentMenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainAgentMenu(QWidget *parent = nullptr);
    ~mainAgentMenu();

private slots:
    // Search Flight Tab
    void on_searchButton_clicked();

    // Book Flight Tab
    void on_bookButton_clicked();
    void onFlightDoubleClicked(QTableWidgetItem *item);

    // Modify Reservation Tab
    void on_modifySearchButton_clicked();
    void on_modifyButton_clicked();

    // Cancel Reservation Tab
    void on_cancelSearchButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::mainAgentMenu *ui;
    QString currentPassengerID; // Store passenger ID being managed

    // Helper functions
    void displayFlights(const json &flights);
    void displayReservations(const json &reservations, QTableWidget *table);
    void showBookingConfirmation(const QString &reservationID,
                                 const QString &flightNumber,
                                 const QString &origin,
                                 const QString &destination,
                                 const QString &seatNumber,
                                 double price);

    // JSON file operations
    json readFromJson(const QString &filename);
    bool writeToJson(const QString &filename, const json &data);

    // Seat validation
    bool isSeatAvailable(const QString &flightNumber, const QString &seatNumber, const json &reservations);
};

#endif // _3_MAINAGENTMENU_H
