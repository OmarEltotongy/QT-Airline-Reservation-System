#ifndef _2A2ADMINMANGEAIRCRAFT_H
#define _2A2ADMINMANGEAIRCRAFT_H

#include <QDialog>
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
#include <QLineEdit>
#include <qstring.h>
#include <qtablewidget.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>

#include <Aircraft.hpp>

namespace Ui {
class adminMangeAircraft;
}

class adminMangeAircraft : public QDialog
{
    Q_OBJECT

public:
    explicit adminMangeAircraft(QWidget *parent = nullptr);
    ~adminMangeAircraft();
private slots:
    void viewAllAirCrafts();
    void on_addAircraftBtn_clicked();

    void on_updateAircraftBtn_clicked();

    void on_removeAircraftBtn_clicked();

    void on_assignAircraftBtn_clicked();

    void on_maintenanceBtn_clicked();

    void on_availabilityBtn_clicked();

    void on_searchOnAircraftToUpdate_clicked();

private:
    Ui::adminMangeAircraft *ui;
    QString aircraftID;
    QString assignedFlight;
    QString availability;
    QString maintenanceSchedule;
    QString model;

    QString currentAircraftID;


};


#endif // _2A2ADMINMANGEAIRCRAFT_H
