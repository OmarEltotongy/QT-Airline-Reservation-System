#ifndef _2A4ADMINGENERATEREPORTS_H
#define _2A4ADMINGENERATEREPORTS_H

#include <QDialog>
#include <QTextStream>
#include <QMessageBox>
#include <userClasses.hpp>


namespace Ui {
class adminGenerateReports;
}

class adminGenerateReports : public QDialog
{
    Q_OBJECT

public:
    explicit adminGenerateReports(QWidget *parent = nullptr);
    ~adminGenerateReports();

private slots:
    void on_generateOperationalBtn_clicked();

    void on_generateMaintenanceBtn_clicked();

    void on_generateUserActivityBtn_clicked();

private:
    Ui::adminGenerateReports *ui;
};

#endif // _2A4ADMINGENERATEREPORTS_H
