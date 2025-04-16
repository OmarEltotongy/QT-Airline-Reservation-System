#ifndef _2A3ADMINMANGEUSERS_H
#define _2A3ADMINMANGEUSERS_H

#include <QDialog>
#include <QMessageBox>
#include <userClasses.hpp>

namespace Ui {
class adminMangeUsers;
}

class adminMangeUsers : public QDialog
{
    Q_OBJECT

public:
    explicit adminMangeUsers(QWidget *parent = nullptr);
    ~adminMangeUsers();

private slots:
    void on_updateSearchOnAdminUsername_clicked();

    void on_updateBookingAgentBtn_clicked();

    void on_updateAdminBtn_clicked();

    void on_updateSearchOnBookingAgentUsername_clicked();

    void on_updateSearchOnPassengerUsername_clicked();

    void on_updatePassengerBtn_clicked();

    void on_deleteUserBtn_clicked();

    void on_searchForUserBtn_clicked();

    void viewAllUsers();
    void on_newAdminBtn_clicked();

    void on_newBookingAgentBtn_clicked();

    void on_newPassengerBtn_clicked();

private:
    Ui::adminMangeUsers *ui;
};

#endif // _2A3ADMINMANGEUSERS_H
