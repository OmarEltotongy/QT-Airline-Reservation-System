#include "_1_mainwindow.h"
#include "ui__1_mainwindow.h"
#include "_2_mainadminmenu.h"
#include "_3_mainagentmenu.h"
#include "_4_mainpassengermenu.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->LoginButton, &QPushButton::clicked, this, &MainWindow::onLoginClicked);

}

void MainWindow::onLoginClicked() {
    QString username = ui->UserNameEdit->text();
    QString password = ui->PasswordEdit->text();
    QString role;

    if (ui->AdminRButton->isChecked()) role = "Admin";
    else if (ui->AgentRButton->isChecked()) role = "Agent";
    else role = "Passenger";

     current_user = user.createUser(
        username.toStdString(),
        password.toStdString(),
        role == "Admin" ? rolesTypes::ADMIN :
            role == "Agent" ? rolesTypes::BOOKING_AGENT :
            rolesTypes::PASSENGER
        );

    if (current_user->login() == LOG_STATE_SUCCESSFUL) {
        if (role == "Admin") {
            // Create and show admin window
            mainAdminMenu *adminWindow = new mainAdminMenu();
            adminWindow->show();

            // Hide the login window
            this->hide();

            // When admin window is closed, show login window again
            connect(adminWindow, &mainAdminMenu::destroyed, this, [this]() {
                this->show();
                current_user.reset();

            });
        }
        else if(role == "Agent")
        {

            mainAgentMenu *agentWindow = new mainAgentMenu();
            agentWindow->show();
            this->hide();

            // When agent window is closed, show login window again
            connect(agentWindow, &mainAdminMenu::destroyed, this, [this]() {
                this->show();
                current_user.reset();

            });
        }
        else if (role == "Passenger")
        {
            mainPassengerMenu *passengerWindow = new mainPassengerMenu(username);
            passengerWindow->show();
            this->hide();

            // When agent window is closed, show login window again
            connect(passengerWindow, &mainAdminMenu::destroyed, this, [this]() {
                this->show();
                current_user.reset();

            });
        }

    }
    else {
        QMessageBox::warning(this, "Error", "Login failed!");
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}
