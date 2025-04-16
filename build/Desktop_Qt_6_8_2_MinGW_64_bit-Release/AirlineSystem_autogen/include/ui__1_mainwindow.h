/********************************************************************************
** Form generated from reading UI file '_1_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__1_MAINWINDOW_H
#define UI__1_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QLabel *subheaderLabel;
    QGroupBox *loginGroupBox;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *RoleGB;
    QHBoxLayout *horizontalLayout;
    QRadioButton *AdminRButton;
    QRadioButton *AgentRButton;
    QRadioButton *PassengerRButton;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *UserNameEdit;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *PasswordEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *LoginButton;
    QPushButton *ExitButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 780);
        MainWindow->setMinimumSize(QSize(900, 700));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #0f2027, stop:0.5 #203a43, stop:1 #2c5364);\n"
"    font-family: 'Segoe UI', system-ui, -apple-system, sans-serif;\n"
"}\n"
"\n"
"QWidget#centralwidget {\n"
"    background-color: rgba(255, 255, 255, 0.08);\n"
"    border-radius: 20px;\n"
"    margin: 60px;\n"
"    border: 1px solid rgba(255,255,255,0.2);\n"
"}\n"
"\n"
"QLabel#headerLabel {\n"
"    font-size: 42px;\n"
"    font-weight: 700;\n"
"    color: white;\n"
"    margin-top: 40px;\n"
"    margin-bottom: 10px;\n"
"    letter-spacing: 1px;\n"
"}\n"
"\n"
"QLabel#subheaderLabel {\n"
"    font-size: 16px;\n"
"    font-weight: 300;\n"
"    color: rgba(255,255,255,0.7);\n"
"    margin-bottom: 40px;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    border: none;\n"
"    margin: 15px;\n"
"    padding-top: 15px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: 500;\n"
"    padding-left: 5px;\n"
"}\n"
"\n"
"Q"
                        "RadioButton {\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    font-weight: 400;\n"
"    margin: 12px;\n"
"    padding: 8px 8px 8px 30px;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 20px;\n"
"    height: 20px;\n"
"    border-radius: 10px;\n"
"    border: 2px solid rgba(255,255,255,0.7);\n"
"    background: transparent;\n"
"    left: 5px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #00c6ff;\n"
"    border-color: #00c6ff;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: rgba(255,255,255,0.1);\n"
"    border: 1px solid rgba(255,255,255,0.2);\n"
"    border-radius: 8px;\n"
"    padding: 14px;\n"
"    font-size: 15px;\n"
"    color: white;\n"
"    min-height: 45px;\n"
"    margin: 8px 0;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #00c6ff;\n"
"    background-color: rgba(255,255,255,0.15);\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: rgba(255,255,255,0.4);\n"
"}\n"
"\n"
"QPushButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y"
                        "2:0, stop:0 #00c6ff, stop:1 #0072ff);\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 16px 32px;\n"
"    border-radius: 8px;\n"
"    font-size: 16px;\n"
"    font-weight: 500;\n"
"    min-width: 140px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #00c6ff, stop:1 #0062ff);\n"
"}\n"
"\n"
"QPushButton#ExitButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #ff416c, stop:1 #ff4b2b);\n"
"}\n"
"\n"
"QPushButton#ExitButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #ff416c, stop:1 #ff3a2b);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("border-radius: 20px;"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(40, 40, 40, 40);
        verticalLayout->setObjectName("verticalLayout");
        headerLabel = new QLabel(centralwidget);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(headerLabel);

        subheaderLabel = new QLabel(centralwidget);
        subheaderLabel->setObjectName("subheaderLabel");
        subheaderLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(subheaderLabel);

        loginGroupBox = new QGroupBox(centralwidget);
        loginGroupBox->setObjectName("loginGroupBox");
        verticalLayout_2 = new QVBoxLayout(loginGroupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        RoleGB = new QGroupBox(loginGroupBox);
        RoleGB->setObjectName("RoleGB");
        horizontalLayout = new QHBoxLayout(RoleGB);
        horizontalLayout->setSpacing(25);
        horizontalLayout->setObjectName("horizontalLayout");
        AdminRButton = new QRadioButton(RoleGB);
        AdminRButton->setObjectName("AdminRButton");
        AdminRButton->setChecked(true);

        horizontalLayout->addWidget(AdminRButton);

        AgentRButton = new QRadioButton(RoleGB);
        AgentRButton->setObjectName("AgentRButton");

        horizontalLayout->addWidget(AgentRButton);

        PassengerRButton = new QRadioButton(RoleGB);
        PassengerRButton->setObjectName("PassengerRButton");

        horizontalLayout->addWidget(PassengerRButton);


        verticalLayout_2->addWidget(RoleGB);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(loginGroupBox);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Elephant")});
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        UserNameEdit = new QLineEdit(loginGroupBox);
        UserNameEdit->setObjectName("UserNameEdit");

        gridLayout->addWidget(UserNameEdit, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(loginGroupBox);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Elephant")});
        label_2->setFont(font1);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        PasswordEdit = new QLineEdit(loginGroupBox);
        PasswordEdit->setObjectName("PasswordEdit");
        PasswordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout_2->addWidget(PasswordEdit, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        LoginButton = new QPushButton(loginGroupBox);
        LoginButton->setObjectName("LoginButton");

        horizontalLayout_2->addWidget(LoginButton);

        ExitButton = new QPushButton(loginGroupBox);
        ExitButton->setObjectName("ExitButton");

        horizontalLayout_2->addWidget(ExitButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(loginGroupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(ExitButton, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        LoginButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Airline System - Premium Portal", nullptr));
        headerLabel->setText(QCoreApplication::translate("MainWindow", "\342\234\210EltoWing Reservation", nullptr));
        subheaderLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt; color:#25aef3;\">Welcome to Omar Eltoutongy Airline Portal</span></p></body></html>", nullptr));
        RoleGB->setTitle(QCoreApplication::translate("MainWindow", "SELECT YOUR ROLE", nullptr));
        AdminRButton->setText(QCoreApplication::translate("MainWindow", "Administrator", nullptr));
        AgentRButton->setText(QCoreApplication::translate("MainWindow", "Booking Agent", nullptr));
        PassengerRButton->setText(QCoreApplication::translate("MainWindow", "Passenger", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-style:italic; color:#ffffff;\">Username:</span></p></body></html>", nullptr));
        UserNameEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your username", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-style:italic; color:#ffffff;\">Password:</span></p></body></html>", nullptr));
        PasswordEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your password", nullptr));
        LoginButton->setText(QCoreApplication::translate("MainWindow", "LOGIN", nullptr));
        ExitButton->setText(QCoreApplication::translate("MainWindow", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__1_MAINWINDOW_H
