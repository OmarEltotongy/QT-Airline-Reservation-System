/********************************************************************************
** Form generated from reading UI file '_2a4admingeneratereports.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__2A4ADMINGENERATEREPORTS_H
#define UI__2A4ADMINGENERATEREPORTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminGenerateReports
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QTabWidget *reportsTabWidget;
    QWidget *operationalReportsTab;
    QVBoxLayout *operationalReportsGroupLayout;
    QLabel *operationalReportLabel;
    QLineEdit *operationalMonthYearEdit;
    QPushButton *generateOperationalBtn;
    QTextEdit *operationalReportText;
    QWidget *maintenanceReportsTab;
    QVBoxLayout *maintenanceReportsGroupLayout;
    QLabel *maintenanceReportLabel;
    QLineEdit *maintenanceMonthYearEdit;
    QPushButton *generateMaintenanceBtn;
    QTextEdit *maintenanceReportText;
    QWidget *userActivityReportsTab;
    QVBoxLayout *userActivityReportsGroupLayout;
    QLabel *userActivityReportLabel;
    QLineEdit *userActivityMonthYearEdit;
    QPushButton *generateUserActivityBtn;
    QTextEdit *userActivityReportText;
    QPushButton *backToMainMenuBtn;

    void setupUi(QDialog *adminGenerateReports)
    {
        if (adminGenerateReports->objectName().isEmpty())
            adminGenerateReports->setObjectName("adminGenerateReports");
        adminGenerateReports->resize(925, 925);
        adminGenerateReports->setMinimumSize(QSize(700, 600));
        adminGenerateReports->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #f8f9fa;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}\n"
"QTabWidget {\n"
"    border: none;\n"
"}\n"
"QTabBar::tab {\n"
"    background: #e0e0e0;\n"
"    color: #2c3e50;\n"
"    padding: 8px 16px;\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"    margin-right: 2px;\n"
"    font-weight: 500;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background: white;\n"
"    border-bottom: 2px solid #3498db;\n"
"    color: #3498db;\n"
"}\n"
"QTabBar::tab:hover {\n"
"    background: #f0f0f0;\n"
"}\n"
"QGroupBox {\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    margin: 15px;\n"
"    padding: 15px;\n"
"    background-color: white;\n"
"    font-size: 14px;\n"
"    color: #2c3e50;\n"
"}\n"
"QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 10px 16px;\n"
"    border-radius: 6px;\n"
"    margin: 8px;\n"
"    font-size: 14px;\n"
"    font-weight: 500;\n"
"    min-width: 1"
                        "80px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #2472a4;\n"
"}\n"
"QLabel#headerLabel {\n"
"    font-size: 24px;\n"
"    font-weight: 600;\n"
"    color: #000000;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        verticalLayout = new QVBoxLayout(adminGenerateReports);
        verticalLayout->setObjectName("verticalLayout");
        headerLabel = new QLabel(adminGenerateReports);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setStyleSheet(QString::fromUtf8("margin-top: 15px; margin-bottom: 15px;"));

        verticalLayout->addWidget(headerLabel);

        reportsTabWidget = new QTabWidget(adminGenerateReports);
        reportsTabWidget->setObjectName("reportsTabWidget");
        operationalReportsTab = new QWidget();
        operationalReportsTab->setObjectName("operationalReportsTab");
        operationalReportsGroupLayout = new QVBoxLayout(operationalReportsTab);
        operationalReportsGroupLayout->setObjectName("operationalReportsGroupLayout");
        operationalReportLabel = new QLabel(operationalReportsTab);
        operationalReportLabel->setObjectName("operationalReportLabel");

        operationalReportsGroupLayout->addWidget(operationalReportLabel);

        operationalMonthYearEdit = new QLineEdit(operationalReportsTab);
        operationalMonthYearEdit->setObjectName("operationalMonthYearEdit");

        operationalReportsGroupLayout->addWidget(operationalMonthYearEdit);

        generateOperationalBtn = new QPushButton(operationalReportsTab);
        generateOperationalBtn->setObjectName("generateOperationalBtn");

        operationalReportsGroupLayout->addWidget(generateOperationalBtn);

        operationalReportText = new QTextEdit(operationalReportsTab);
        operationalReportText->setObjectName("operationalReportText");
        operationalReportText->setReadOnly(true);

        operationalReportsGroupLayout->addWidget(operationalReportText);

        reportsTabWidget->addTab(operationalReportsTab, QString());
        maintenanceReportsTab = new QWidget();
        maintenanceReportsTab->setObjectName("maintenanceReportsTab");
        maintenanceReportsGroupLayout = new QVBoxLayout(maintenanceReportsTab);
        maintenanceReportsGroupLayout->setObjectName("maintenanceReportsGroupLayout");
        maintenanceReportLabel = new QLabel(maintenanceReportsTab);
        maintenanceReportLabel->setObjectName("maintenanceReportLabel");

        maintenanceReportsGroupLayout->addWidget(maintenanceReportLabel);

        maintenanceMonthYearEdit = new QLineEdit(maintenanceReportsTab);
        maintenanceMonthYearEdit->setObjectName("maintenanceMonthYearEdit");

        maintenanceReportsGroupLayout->addWidget(maintenanceMonthYearEdit);

        generateMaintenanceBtn = new QPushButton(maintenanceReportsTab);
        generateMaintenanceBtn->setObjectName("generateMaintenanceBtn");

        maintenanceReportsGroupLayout->addWidget(generateMaintenanceBtn);

        maintenanceReportText = new QTextEdit(maintenanceReportsTab);
        maintenanceReportText->setObjectName("maintenanceReportText");
        maintenanceReportText->setReadOnly(true);

        maintenanceReportsGroupLayout->addWidget(maintenanceReportText);

        reportsTabWidget->addTab(maintenanceReportsTab, QString());
        userActivityReportsTab = new QWidget();
        userActivityReportsTab->setObjectName("userActivityReportsTab");
        userActivityReportsGroupLayout = new QVBoxLayout(userActivityReportsTab);
        userActivityReportsGroupLayout->setObjectName("userActivityReportsGroupLayout");
        userActivityReportLabel = new QLabel(userActivityReportsTab);
        userActivityReportLabel->setObjectName("userActivityReportLabel");

        userActivityReportsGroupLayout->addWidget(userActivityReportLabel);

        userActivityMonthYearEdit = new QLineEdit(userActivityReportsTab);
        userActivityMonthYearEdit->setObjectName("userActivityMonthYearEdit");

        userActivityReportsGroupLayout->addWidget(userActivityMonthYearEdit);

        generateUserActivityBtn = new QPushButton(userActivityReportsTab);
        generateUserActivityBtn->setObjectName("generateUserActivityBtn");

        userActivityReportsGroupLayout->addWidget(generateUserActivityBtn);

        userActivityReportText = new QTextEdit(userActivityReportsTab);
        userActivityReportText->setObjectName("userActivityReportText");
        userActivityReportText->setReadOnly(true);

        userActivityReportsGroupLayout->addWidget(userActivityReportText);

        reportsTabWidget->addTab(userActivityReportsTab, QString());

        verticalLayout->addWidget(reportsTabWidget);

        backToMainMenuBtn = new QPushButton(adminGenerateReports);
        backToMainMenuBtn->setObjectName("backToMainMenuBtn");

        verticalLayout->addWidget(backToMainMenuBtn);


        retranslateUi(adminGenerateReports);
        QObject::connect(backToMainMenuBtn, &QPushButton::clicked, adminGenerateReports, qOverload<>(&QDialog::deleteLater));

        reportsTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(adminGenerateReports);
    } // setupUi

    void retranslateUi(QDialog *adminGenerateReports)
    {
        adminGenerateReports->setWindowTitle(QCoreApplication::translate("adminGenerateReports", "Airline System - Generate Reports", nullptr));
        headerLabel->setText(QCoreApplication::translate("adminGenerateReports", "Report Generation", nullptr));
        operationalReportLabel->setText(QCoreApplication::translate("adminGenerateReports", "Enter Month and Year (MM-YYYY):", nullptr));
        generateOperationalBtn->setText(QCoreApplication::translate("adminGenerateReports", "Generate Operational Report", nullptr));
        reportsTabWidget->setTabText(reportsTabWidget->indexOf(operationalReportsTab), QCoreApplication::translate("adminGenerateReports", "\360\237\223\212 Operational Reports", nullptr));
        maintenanceReportLabel->setText(QCoreApplication::translate("adminGenerateReports", "Enter Month and Year (MM-YYYY):", nullptr));
        generateMaintenanceBtn->setText(QCoreApplication::translate("adminGenerateReports", "Generate Maintenance Report", nullptr));
        reportsTabWidget->setTabText(reportsTabWidget->indexOf(maintenanceReportsTab), QCoreApplication::translate("adminGenerateReports", "\360\237\224\247 Maintenance Reports", nullptr));
        userActivityReportLabel->setText(QCoreApplication::translate("adminGenerateReports", "Enter Month and Year (MM-YYYY):", nullptr));
        generateUserActivityBtn->setText(QCoreApplication::translate("adminGenerateReports", "Generate User Activity Report", nullptr));
        reportsTabWidget->setTabText(reportsTabWidget->indexOf(userActivityReportsTab), QCoreApplication::translate("adminGenerateReports", "\360\237\221\245 User Activity Reports", nullptr));
        backToMainMenuBtn->setText(QCoreApplication::translate("adminGenerateReports", "Back to Main Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminGenerateReports: public Ui_adminGenerateReports {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__2A4ADMINGENERATEREPORTS_H
