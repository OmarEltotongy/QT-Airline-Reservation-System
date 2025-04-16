#ifndef _2_MAINADMINMENU_H
#define _2_MAINADMINMENU_H

#include <QDialog>

namespace Ui {
class mainAdminMenu;
}

class mainAdminMenu : public QDialog
{
    Q_OBJECT

public:
    explicit mainAdminMenu(QWidget *parent = nullptr);
    ~mainAdminMenu();

private slots:
    void onManageFlightClicked();
    void onManageAircraftClicked();
    void onManageUserClicked();
    void generateReports();
private:
    Ui::mainAdminMenu *ui;
};

#endif // _2_MAINADMINMENU_H
