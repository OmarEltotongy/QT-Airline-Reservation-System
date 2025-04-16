#include "_2_mainadminmenu.h"
#include "ui__2_mainadminmenu.h"
#include "_2a1adminmanageflights.h"
#include "_2a2adminmangeaircraft.h"
#include "_2a3adminmangeusers.h"
#include "_2a4admingeneratereports.h"


mainAdminMenu::mainAdminMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainAdminMenu)
{
    ui->setupUi(this);
    connect(ui->mangeFlightsBtn, &QPushButton::clicked, this, &mainAdminMenu::onManageFlightClicked);
    connect(ui->mangeAircraftsBtn, &QPushButton::clicked, this, &mainAdminMenu::onManageAircraftClicked);
    connect(ui->mangeUsersBtn, &QPushButton::clicked, this, &mainAdminMenu::onManageUserClicked);
    connect(ui->generateReportsBtn, &QPushButton::clicked, this, &mainAdminMenu::generateReports);
    setWindowTitle("EltoWing System - Admin Dashboard");

}

void mainAdminMenu::onManageFlightClicked()
{
    // Create and show manage flight window
    adminManageFlights *flightAdminWindow = new adminManageFlights();
    flightAdminWindow->show();

    // Hide the admin window
    this->hide();

    // When admin window is closed, show admin window again
    connect(flightAdminWindow, &mainAdminMenu::destroyed, this, [this]() {
        this->show();
    });

}

void mainAdminMenu::onManageAircraftClicked()
{
    adminMangeAircraft *aircraftAdminWindow = new adminMangeAircraft();
    aircraftAdminWindow->show();

    // Hide the admin window
    this->hide();

    // When admin window is closed, show admin window again
    connect(aircraftAdminWindow, &mainAdminMenu::destroyed, this, [this]() {
        this->show();
    });

}

void mainAdminMenu::onManageUserClicked()
{

    adminMangeUsers *userAdminWindow = new adminMangeUsers();
    userAdminWindow->show();

    // Hide the admin window
    this->hide();

    // When admin window is closed, show admin window again
    connect(userAdminWindow, &mainAdminMenu::destroyed, this, [this]() {
        this->show();
    });


}

void mainAdminMenu::generateReports()
{
    adminGenerateReports *reportsAdminWindow = new adminGenerateReports();
    reportsAdminWindow->show();

    // Hide the admin window
    this->hide();

    // When admin window is closed, show admin window again
    connect(reportsAdminWindow, &mainAdminMenu::destroyed, this, [this]() {
        this->show();
    });

}

mainAdminMenu::~mainAdminMenu()
{
    delete ui;
}
