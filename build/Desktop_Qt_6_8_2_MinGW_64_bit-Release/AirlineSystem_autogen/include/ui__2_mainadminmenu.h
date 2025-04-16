/********************************************************************************
** Form generated from reading UI file '_2_mainadminmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__2_MAINADMINMENU_H
#define UI__2_MAINADMINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_mainAdminMenu
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *mangeFlightsBtn;
    QPushButton *mangeAircraftsBtn;
    QPushButton *mangeUsersBtn;
    QPushButton *generateReportsBtn;
    QPushButton *LogoutBtn;

    void setupUi(QDialog *mainAdminMenu)
    {
        if (mainAdminMenu->objectName().isEmpty())
            mainAdminMenu->setObjectName("mainAdminMenu");
        mainAdminMenu->resize(700, 600);
        mainAdminMenu->setMinimumSize(QSize(700, 600));
        mainAdminMenu->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #f8f9fa;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}\n"
"QGroupBox {\n"
"    border: 2px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    margin: 20px;\n"
"    padding: 20px;\n"
"    background-color: white;\n"
"    font-size: 16px;\n"
"    font-weight: 600;\n"
"    color: #2c3e50;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 8px;\n"
"    color: #3498db;\n"
"}\n"
"QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 12px 20px;\n"
"    border-radius: 6px;\n"
"    margin: 8px;\n"
"    font-size: 14px;\n"
"    font-weight: 500;\n"
"    min-width: 200px;\n"
"    text-align: left;\n"
"    padding-left: 30px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #2472a4;\n"
"}\n"
"QPushButton#LogoutBtn {\n"
"    background-color: #e74c3c;\n"
"    margin: 20px;\n"
"    text-align: cent"
                        "er;\n"
"    padding-left: 20px;\n"
"}\n"
"QPushButton#LogoutBtn:hover {\n"
"    background-color: #c0392b;\n"
"}\n"
"QLabel#headerLabel {\n"
"    font-size: 24px;\n"
"    font-weight: 600;\n"
"    color: #2c3e50;\n"
"    qproperty-alignment: AlignCenter;\n"
"}"));
        verticalLayout = new QVBoxLayout(mainAdminMenu);
        verticalLayout->setObjectName("verticalLayout");
        headerLabel = new QLabel(mainAdminMenu);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setStyleSheet(QString::fromUtf8("margin-top: 20px; margin-bottom: 10px;"));

        verticalLayout->addWidget(headerLabel);

        groupBox = new QGroupBox(mainAdminMenu);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        mangeFlightsBtn = new QPushButton(groupBox);
        mangeFlightsBtn->setObjectName("mangeFlightsBtn");
        mangeFlightsBtn->setStyleSheet(QString::fromUtf8("padding-left: 30px;"));

        verticalLayout_2->addWidget(mangeFlightsBtn);

        mangeAircraftsBtn = new QPushButton(groupBox);
        mangeAircraftsBtn->setObjectName("mangeAircraftsBtn");

        verticalLayout_2->addWidget(mangeAircraftsBtn);

        mangeUsersBtn = new QPushButton(groupBox);
        mangeUsersBtn->setObjectName("mangeUsersBtn");

        verticalLayout_2->addWidget(mangeUsersBtn);

        generateReportsBtn = new QPushButton(groupBox);
        generateReportsBtn->setObjectName("generateReportsBtn");

        verticalLayout_2->addWidget(generateReportsBtn);


        verticalLayout->addWidget(groupBox);

        LogoutBtn = new QPushButton(mainAdminMenu);
        LogoutBtn->setObjectName("LogoutBtn");

        verticalLayout->addWidget(LogoutBtn);


        retranslateUi(mainAdminMenu);
        QObject::connect(LogoutBtn, &QPushButton::clicked, mainAdminMenu, qOverload<>(&QDialog::deleteLater));

        QMetaObject::connectSlotsByName(mainAdminMenu);
    } // setupUi

    void retranslateUi(QDialog *mainAdminMenu)
    {
        mainAdminMenu->setWindowTitle(QCoreApplication::translate("mainAdminMenu", "Airline System - Admin Dashboard", nullptr));
        headerLabel->setText(QCoreApplication::translate("mainAdminMenu", "Admin Dashboard", nullptr));
        groupBox->setTitle(QCoreApplication::translate("mainAdminMenu", "Management Options", nullptr));
        mangeFlightsBtn->setText(QCoreApplication::translate("mainAdminMenu", "\342\234\210 Manage Flights", nullptr));
        mangeAircraftsBtn->setText(QCoreApplication::translate("mainAdminMenu", "\360\237\233\251 Manage Aircraft", nullptr));
        mangeUsersBtn->setText(QCoreApplication::translate("mainAdminMenu", "\360\237\221\245 Manage Users", nullptr));
        generateReportsBtn->setText(QCoreApplication::translate("mainAdminMenu", "\360\237\223\212 Generate Reports", nullptr));
        LogoutBtn->setText(QCoreApplication::translate("mainAdminMenu", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainAdminMenu: public Ui_mainAdminMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__2_MAINADMINMENU_H
