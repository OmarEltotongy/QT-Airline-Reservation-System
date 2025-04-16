#ifndef _1_MAINWINDOW_H
#define _1_MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "USERS_HPP/userClasses.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginClicked();

private:
    Ui::MainWindow *ui;
    userFactory user;
    std::unique_ptr<User> current_user;  // Add this line


};
#endif // _1_MAINWINDOW_H
