#ifndef _2A1ADMINMANAGEFLIGHTS_H
#define _2A1ADMINMANAGEFLIGHTS_H

#include <QDialog>
#include <QLineEdit>
#include <qstring.h>
#include <QLabel>
#include "include/FLIGHT_HPP/Flight.hpp"
#include <qtablewidget.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include "include/AIRCRAFT_HPP/Aircraft.hpp"
#include "../ENUMS/flights_enum.hpp"
#include <QFile>
#include <QJsonDocument>
#include <QMessageBox>
#include <QDateTime>
#include <QCheckBox>  // For QCheckBox
#include <QHBoxLayout> // For QHBoxLayout
#include <algorithm> // for std::transform
#include <cctype>    // for ::tolower/::toupper
#include <QTimer>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>


namespace Ui {
class adminManageFlights;
}

class adminManageFlights : public QDialog
{
    Q_OBJECT

public:
    explicit adminManageFlights(QWidget *parent = nullptr, Administrator *admin = nullptr);
    std::string stdAircraftID;
    ~adminManageFlights();

private slots:
    void on_nextAddFlightBtn_clicked();
    void on_finishFlightBtn_clicked();
    void on_assignPilotBtn_clicked(QTableWidget *pilotsTable , QTableWidget *attendantsTable);
    void resetForm();

    void on_searchOnFlightToUpdate_clicked();

    void on_updateFlightBtn_clicked();

    void on_searchOnFlightToUpdateCrew_clicked();

    void on_updateAssignedCrewBtn_clicked();

    void on_updateCrewBtn_clicked();

    void on_searchOnFlightToRemove_clicked();

    void on_removeFlightBtn_clicked();
    void viewFlightsIsPressed();

private:
    Ui::adminManageFlights *ui;
    Administrator *admin;
    Flight *currentFlight;
    QList<QString> selectedPilots;
    QList<QString> selectedAttendants;

    QString currentFlightNumber;
    QString origin;
    QString destination ;
    QString departure;
    QString arrival;
    QString aircraftID;
    QString oldAircraftID;
    QTableWidget attendantsTable;
    QTableWidget pilotsTable;

    int status ;
    int maxSeats;
    double price;
    QString gate;
    QStringList previousPilots ;
    QStringList previousAttendants ;
    QLabel chosenPilot;
    QLabel chosenFA;
    bool m_isResetting = false;

    void loadCrewData(QTableWidget *pilotsTable, QTableWidget *attendantsTable );
    void updateAssignedCrewDisplay(QTableWidget *pilotsTable, QTableWidget *attendantsTable,QLabel*chosenPilot,QLabel* chosenFA);
    void updateCrewStatus(const QString &pilotID, const QStringList &attendantIDs, const QString &flightNumber);
    void disconnectAllFieldSignals();
    void reconnectFieldSignals();
    bool validateForm(QString &aircraftID);
    bool checkForAircraft(QString &aircraft);
    void setAircraftAvailability(const QString& aircraftID, bool available);
    void freeOldAircraft(const QString& oldAircraftID);
    void loadCrewDataWithSelection(QTableWidget* pilotsTable, QTableWidget* attendantsTable, const json& flightData);
    void updateCrewStatusForFlightChange();
    void updateFlightTable(const QJsonArray& flights);
};

#endif // _2A1ADMINMANAGEFLIGHTS_H
