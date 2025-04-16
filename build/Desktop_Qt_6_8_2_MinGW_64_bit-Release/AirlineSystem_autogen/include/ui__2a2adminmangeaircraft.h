/********************************************************************************
** Form generated from reading UI file '_2a2adminmangeaircraft.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__2A2ADMINMANGEAIRCRAFT_H
#define UI__2A2ADMINMANGEAIRCRAFT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminMangeAircraft
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QTabWidget *aircraftTabWidget;
    QWidget *addAircraftTab;
    QVBoxLayout *addAircraftLayout;
    QGroupBox *addAircraftGroup;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLineEdit *aircraftIDlineEdit;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_13;
    QSpacerItem *horizontalSpacer;
    QLineEdit *aircraftModellineEdit;
    QLabel *label_13;
    QGridLayout *gridLayout_2;
    QLineEdit *aircraftAssignedFlightlineEdit;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_4;
    QLineEdit *aircraftAvalineEdit;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *aircraftMainSchelineEdit;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *addAircraftBtn;
    QWidget *updateAircraftTab;
    QVBoxLayout *updateAircraftLayout;
    QGroupBox *updateAircraftGroup;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_8;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_10;
    QLineEdit *updateAircraftIDlineEdit;
    QPushButton *searchOnAircraftToUpdate;
    QGridLayout *gridLayout_14;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *updateAircraftModellineEdit;
    QLabel *label_14;
    QGridLayout *gridLayout_7;
    QLineEdit *updateAircraftAssignedFlightlineEdit;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_9;
    QGridLayout *gridLayout_6;
    QLineEdit *updateAircraftAvalineEdit;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QLineEdit *updateAircraftMainSchelineEdit;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *updateAircraftBtn;
    QWidget *removeAircraftTab;
    QVBoxLayout *removeAircraftLayout;
    QGroupBox *removeAircraftGroup;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_9;
    QLabel *label_9;
    QLineEdit *removeAircraftIDlineEdit;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *removeAircraftBtn;
    QWidget *assignAircraftTab;
    QVBoxLayout *assignAircraftLayout;
    QGroupBox *assignAircraftGroup;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_10;
    QLabel *label_10;
    QLineEdit *assignAircraftIDlineEdit;
    QSpacerItem *horizontalSpacer_12;
    QGridLayout *gridLayout_11;
    QLineEdit *assignAircraftAssignedFlightlineEdit;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *assignAircraftBtn;
    QWidget *maintenanceTab;
    QVBoxLayout *maintenanceLayout;
    QGroupBox *maintenanceGroup;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_16;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_14;
    QLineEdit *scheduleAircraftIDlineEdit;
    QGridLayout *gridLayout_12;
    QLabel *label_16;
    QLineEdit *scheduleAircraftMainSchelineEdit;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *maintenanceBtn;
    QWidget *availabilityTab;
    QVBoxLayout *availabilityLayout;
    QGroupBox *availabilityGroup;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_15;
    QLineEdit *checkAvaAircraftIDlineEdit;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *availabilityBtn;
    QWidget *viewAircraftTab;
    QVBoxLayout *viewAircraftLayout;
    QGroupBox *viewAircraftGroup;
    QVBoxLayout *viewAircraftGroupLayout;
    QTableWidget *viewAircraftTableWidget;
    QPushButton *BackToMainMenuBtn;

    void setupUi(QDialog *adminMangeAircraft)
    {
        if (adminMangeAircraft->objectName().isEmpty())
            adminMangeAircraft->setObjectName("adminMangeAircraft");
        adminMangeAircraft->resize(925, 925);
        adminMangeAircraft->setMinimumSize(QSize(700, 600));
        adminMangeAircraft->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
        verticalLayout = new QVBoxLayout(adminMangeAircraft);
        verticalLayout->setObjectName("verticalLayout");
        headerLabel = new QLabel(adminMangeAircraft);
        headerLabel->setObjectName("headerLabel");
        headerLabel->setStyleSheet(QString::fromUtf8("margin-top: 15px; margin-bottom: 15px;"));

        verticalLayout->addWidget(headerLabel);

        aircraftTabWidget = new QTabWidget(adminMangeAircraft);
        aircraftTabWidget->setObjectName("aircraftTabWidget");
        addAircraftTab = new QWidget();
        addAircraftTab->setObjectName("addAircraftTab");
        addAircraftLayout = new QVBoxLayout(addAircraftTab);
        addAircraftLayout->setObjectName("addAircraftLayout");
        addAircraftGroup = new QGroupBox(addAircraftTab);
        addAircraftGroup->setObjectName("addAircraftGroup");
        verticalLayout_2 = new QVBoxLayout(addAircraftGroup);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        label = new QLabel(addAircraftGroup);
        label->setObjectName("label");

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        aircraftIDlineEdit = new QLineEdit(addAircraftGroup);
        aircraftIDlineEdit->setObjectName("aircraftIDlineEdit");

        gridLayout_3->addWidget(aircraftIDlineEdit, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(110, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName("gridLayout_13");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_13->addItem(horizontalSpacer, 0, 1, 1, 2);

        aircraftModellineEdit = new QLineEdit(addAircraftGroup);
        aircraftModellineEdit->setObjectName("aircraftModellineEdit");

        gridLayout_13->addWidget(aircraftModellineEdit, 0, 3, 1, 1);

        label_13 = new QLabel(addAircraftGroup);
        label_13->setObjectName("label_13");

        gridLayout_13->addWidget(label_13, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_13);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        aircraftAssignedFlightlineEdit = new QLineEdit(addAircraftGroup);
        aircraftAssignedFlightlineEdit->setObjectName("aircraftAssignedFlightlineEdit");

        gridLayout_2->addWidget(aircraftAssignedFlightlineEdit, 0, 2, 1, 1);

        label_2 = new QLabel(addAircraftGroup);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(60, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        aircraftAvalineEdit = new QLineEdit(addAircraftGroup);
        aircraftAvalineEdit->setObjectName("aircraftAvalineEdit");

        gridLayout_4->addWidget(aircraftAvalineEdit, 0, 2, 1, 1);

        label_4 = new QLabel(addAircraftGroup);
        label_4->setObjectName("label_4");

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(55, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_3 = new QLabel(addAircraftGroup);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        aircraftMainSchelineEdit = new QLineEdit(addAircraftGroup);
        aircraftMainSchelineEdit->setObjectName("aircraftMainSchelineEdit");

        gridLayout->addWidget(aircraftMainSchelineEdit, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(25, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        addAircraftBtn = new QPushButton(addAircraftGroup);
        addAircraftBtn->setObjectName("addAircraftBtn");

        verticalLayout_2->addWidget(addAircraftBtn);


        addAircraftLayout->addWidget(addAircraftGroup);

        aircraftTabWidget->addTab(addAircraftTab, QString());
        updateAircraftTab = new QWidget();
        updateAircraftTab->setObjectName("updateAircraftTab");
        updateAircraftLayout = new QVBoxLayout(updateAircraftTab);
        updateAircraftLayout->setObjectName("updateAircraftLayout");
        updateAircraftGroup = new QGroupBox(updateAircraftTab);
        updateAircraftGroup->setObjectName("updateAircraftGroup");
        verticalLayout_3 = new QVBoxLayout(updateAircraftGroup);
        verticalLayout_3->setObjectName("verticalLayout_3");
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName("gridLayout_8");
        label_8 = new QLabel(updateAircraftGroup);
        label_8->setObjectName("label_8");

        gridLayout_8->addWidget(label_8, 0, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(110, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_10, 0, 1, 1, 1);

        updateAircraftIDlineEdit = new QLineEdit(updateAircraftGroup);
        updateAircraftIDlineEdit->setObjectName("updateAircraftIDlineEdit");

        gridLayout_8->addWidget(updateAircraftIDlineEdit, 0, 2, 1, 1);

        searchOnAircraftToUpdate = new QPushButton(updateAircraftGroup);
        searchOnAircraftToUpdate->setObjectName("searchOnAircraftToUpdate");

        gridLayout_8->addWidget(searchOnAircraftToUpdate, 0, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout_8);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName("gridLayout_14");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_14->addItem(horizontalSpacer_6, 0, 1, 1, 2);

        updateAircraftModellineEdit = new QLineEdit(updateAircraftGroup);
        updateAircraftModellineEdit->setObjectName("updateAircraftModellineEdit");

        gridLayout_14->addWidget(updateAircraftModellineEdit, 0, 3, 1, 1);

        label_14 = new QLabel(updateAircraftGroup);
        label_14->setObjectName("label_14");

        gridLayout_14->addWidget(label_14, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_14);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName("gridLayout_7");
        updateAircraftAssignedFlightlineEdit = new QLineEdit(updateAircraftGroup);
        updateAircraftAssignedFlightlineEdit->setObjectName("updateAircraftAssignedFlightlineEdit");

        gridLayout_7->addWidget(updateAircraftAssignedFlightlineEdit, 0, 2, 1, 1);

        label_7 = new QLabel(updateAircraftGroup);
        label_7->setObjectName("label_7");

        gridLayout_7->addWidget(label_7, 0, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(60, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_9, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_7);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName("gridLayout_6");
        updateAircraftAvalineEdit = new QLineEdit(updateAircraftGroup);
        updateAircraftAvalineEdit->setObjectName("updateAircraftAvalineEdit");

        gridLayout_6->addWidget(updateAircraftAvalineEdit, 0, 2, 1, 1);

        label_6 = new QLabel(updateAircraftGroup);
        label_6->setObjectName("label_6");

        gridLayout_6->addWidget(label_6, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(55, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_6);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        label_5 = new QLabel(updateAircraftGroup);
        label_5->setObjectName("label_5");

        gridLayout_5->addWidget(label_5, 0, 0, 1, 1);

        updateAircraftMainSchelineEdit = new QLineEdit(updateAircraftGroup);
        updateAircraftMainSchelineEdit->setObjectName("updateAircraftMainSchelineEdit");

        gridLayout_5->addWidget(updateAircraftMainSchelineEdit, 0, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(25, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_5);

        updateAircraftBtn = new QPushButton(updateAircraftGroup);
        updateAircraftBtn->setObjectName("updateAircraftBtn");

        verticalLayout_3->addWidget(updateAircraftBtn);


        updateAircraftLayout->addWidget(updateAircraftGroup);

        aircraftTabWidget->addTab(updateAircraftTab, QString());
        removeAircraftTab = new QWidget();
        removeAircraftTab->setObjectName("removeAircraftTab");
        removeAircraftLayout = new QVBoxLayout(removeAircraftTab);
        removeAircraftLayout->setObjectName("removeAircraftLayout");
        removeAircraftGroup = new QGroupBox(removeAircraftTab);
        removeAircraftGroup->setObjectName("removeAircraftGroup");
        verticalLayout_4 = new QVBoxLayout(removeAircraftGroup);
        verticalLayout_4->setObjectName("verticalLayout_4");
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName("gridLayout_9");
        label_9 = new QLabel(removeAircraftGroup);
        label_9->setObjectName("label_9");

        gridLayout_9->addWidget(label_9, 0, 0, 1, 1);

        removeAircraftIDlineEdit = new QLineEdit(removeAircraftGroup);
        removeAircraftIDlineEdit->setObjectName("removeAircraftIDlineEdit");

        gridLayout_9->addWidget(removeAircraftIDlineEdit, 0, 2, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(110, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_11, 0, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_9);

        removeAircraftBtn = new QPushButton(removeAircraftGroup);
        removeAircraftBtn->setObjectName("removeAircraftBtn");

        verticalLayout_4->addWidget(removeAircraftBtn);


        removeAircraftLayout->addWidget(removeAircraftGroup);

        aircraftTabWidget->addTab(removeAircraftTab, QString());
        assignAircraftTab = new QWidget();
        assignAircraftTab->setObjectName("assignAircraftTab");
        assignAircraftLayout = new QVBoxLayout(assignAircraftTab);
        assignAircraftLayout->setObjectName("assignAircraftLayout");
        assignAircraftGroup = new QGroupBox(assignAircraftTab);
        assignAircraftGroup->setObjectName("assignAircraftGroup");
        verticalLayout_5 = new QVBoxLayout(assignAircraftGroup);
        verticalLayout_5->setObjectName("verticalLayout_5");
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName("gridLayout_10");
        label_10 = new QLabel(assignAircraftGroup);
        label_10->setObjectName("label_10");

        gridLayout_10->addWidget(label_10, 0, 0, 1, 1);

        assignAircraftIDlineEdit = new QLineEdit(assignAircraftGroup);
        assignAircraftIDlineEdit->setObjectName("assignAircraftIDlineEdit");

        gridLayout_10->addWidget(assignAircraftIDlineEdit, 0, 2, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(110, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_12, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_10);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName("gridLayout_11");
        assignAircraftAssignedFlightlineEdit = new QLineEdit(assignAircraftGroup);
        assignAircraftAssignedFlightlineEdit->setObjectName("assignAircraftAssignedFlightlineEdit");

        gridLayout_11->addWidget(assignAircraftAssignedFlightlineEdit, 0, 2, 1, 1);

        label_11 = new QLabel(assignAircraftGroup);
        label_11->setObjectName("label_11");

        gridLayout_11->addWidget(label_11, 0, 0, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(60, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_13, 0, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_11);

        assignAircraftBtn = new QPushButton(assignAircraftGroup);
        assignAircraftBtn->setObjectName("assignAircraftBtn");

        verticalLayout_5->addWidget(assignAircraftBtn);


        assignAircraftLayout->addWidget(assignAircraftGroup);

        aircraftTabWidget->addTab(assignAircraftTab, QString());
        maintenanceTab = new QWidget();
        maintenanceTab->setObjectName("maintenanceTab");
        maintenanceLayout = new QVBoxLayout(maintenanceTab);
        maintenanceLayout->setObjectName("maintenanceLayout");
        maintenanceGroup = new QGroupBox(maintenanceTab);
        maintenanceGroup->setObjectName("maintenanceGroup");
        verticalLayout_6 = new QVBoxLayout(maintenanceGroup);
        verticalLayout_6->setObjectName("verticalLayout_6");
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setObjectName("gridLayout_16");
        label_12 = new QLabel(maintenanceGroup);
        label_12->setObjectName("label_12");

        gridLayout_16->addWidget(label_12, 0, 0, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(110, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_16->addItem(horizontalSpacer_14, 0, 1, 1, 1);

        scheduleAircraftIDlineEdit = new QLineEdit(maintenanceGroup);
        scheduleAircraftIDlineEdit->setObjectName("scheduleAircraftIDlineEdit");

        gridLayout_16->addWidget(scheduleAircraftIDlineEdit, 0, 2, 1, 1);


        verticalLayout_6->addLayout(gridLayout_16);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName("gridLayout_12");
        label_16 = new QLabel(maintenanceGroup);
        label_16->setObjectName("label_16");

        gridLayout_12->addWidget(label_16, 0, 0, 1, 1);

        scheduleAircraftMainSchelineEdit = new QLineEdit(maintenanceGroup);
        scheduleAircraftMainSchelineEdit->setObjectName("scheduleAircraftMainSchelineEdit");

        gridLayout_12->addWidget(scheduleAircraftMainSchelineEdit, 0, 2, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(25, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_16, 0, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_12);

        maintenanceBtn = new QPushButton(maintenanceGroup);
        maintenanceBtn->setObjectName("maintenanceBtn");

        verticalLayout_6->addWidget(maintenanceBtn);


        maintenanceLayout->addWidget(maintenanceGroup);

        aircraftTabWidget->addTab(maintenanceTab, QString());
        availabilityTab = new QWidget();
        availabilityTab->setObjectName("availabilityTab");
        availabilityLayout = new QVBoxLayout(availabilityTab);
        availabilityLayout->setObjectName("availabilityLayout");
        availabilityGroup = new QGroupBox(availabilityTab);
        availabilityGroup->setObjectName("availabilityGroup");
        verticalLayout_7 = new QVBoxLayout(availabilityGroup);
        verticalLayout_7->setObjectName("verticalLayout_7");
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName("gridLayout_15");
        checkAvaAircraftIDlineEdit = new QLineEdit(availabilityGroup);
        checkAvaAircraftIDlineEdit->setObjectName("checkAvaAircraftIDlineEdit");

        gridLayout_15->addWidget(checkAvaAircraftIDlineEdit, 0, 2, 1, 1);

        label_15 = new QLabel(availabilityGroup);
        label_15->setObjectName("label_15");

        gridLayout_15->addWidget(label_15, 0, 0, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(110, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        gridLayout_15->addItem(horizontalSpacer_15, 0, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout_15);

        availabilityBtn = new QPushButton(availabilityGroup);
        availabilityBtn->setObjectName("availabilityBtn");

        verticalLayout_7->addWidget(availabilityBtn);


        availabilityLayout->addWidget(availabilityGroup);

        aircraftTabWidget->addTab(availabilityTab, QString());
        viewAircraftTab = new QWidget();
        viewAircraftTab->setObjectName("viewAircraftTab");
        viewAircraftLayout = new QVBoxLayout(viewAircraftTab);
        viewAircraftLayout->setObjectName("viewAircraftLayout");
        viewAircraftGroup = new QGroupBox(viewAircraftTab);
        viewAircraftGroup->setObjectName("viewAircraftGroup");
        viewAircraftGroupLayout = new QVBoxLayout(viewAircraftGroup);
        viewAircraftGroupLayout->setObjectName("viewAircraftGroupLayout");
        viewAircraftTableWidget = new QTableWidget(viewAircraftGroup);
        viewAircraftTableWidget->setObjectName("viewAircraftTableWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(viewAircraftTableWidget->sizePolicy().hasHeightForWidth());
        viewAircraftTableWidget->setSizePolicy(sizePolicy);

        viewAircraftGroupLayout->addWidget(viewAircraftTableWidget);


        viewAircraftLayout->addWidget(viewAircraftGroup);

        aircraftTabWidget->addTab(viewAircraftTab, QString());

        verticalLayout->addWidget(aircraftTabWidget);

        BackToMainMenuBtn = new QPushButton(adminMangeAircraft);
        BackToMainMenuBtn->setObjectName("BackToMainMenuBtn");

        verticalLayout->addWidget(BackToMainMenuBtn);


        retranslateUi(adminMangeAircraft);
        QObject::connect(BackToMainMenuBtn, &QPushButton::clicked, adminMangeAircraft, qOverload<>(&QDialog::deleteLater));

        aircraftTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(adminMangeAircraft);
    } // setupUi

    void retranslateUi(QDialog *adminMangeAircraft)
    {
        adminMangeAircraft->setWindowTitle(QCoreApplication::translate("adminMangeAircraft", "Airline System - Manage Aircraft", nullptr));
        headerLabel->setText(QCoreApplication::translate("adminMangeAircraft", "Aircraft Management", nullptr));
        addAircraftGroup->setTitle(QString());
        label->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Aircraft ID</span></p></body></html>", nullptr));
        aircraftIDlineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Aircraft ID", nullptr));
        aircraftModellineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Aircraft Model", nullptr));
        label_13->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Model</span></p></body></html>", nullptr));
        aircraftAssignedFlightlineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Assigned Flight Number or Keep it Blank", nullptr));
        label_2->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Assigned Flight</span></p></body></html>", nullptr));
        aircraftAvalineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Availability state: 0 For False, 1 For True", nullptr));
        label_4->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Availability</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Maintenance Schedule</span></p></body></html>", nullptr));
        aircraftMainSchelineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Maintenance Schedule (DD-MM-YYYY)", nullptr));
        addAircraftBtn->setText(QCoreApplication::translate("adminMangeAircraft", "Add New Aircraft", nullptr));
        aircraftTabWidget->setTabText(aircraftTabWidget->indexOf(addAircraftTab), QCoreApplication::translate("adminMangeAircraft", "\342\236\225 Add Aircraft", nullptr));
        updateAircraftGroup->setTitle(QString());
        label_8->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Aircraft ID</span></p></body></html>", nullptr));
        updateAircraftIDlineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Aircraft ID", nullptr));
        searchOnAircraftToUpdate->setText(QCoreApplication::translate("adminMangeAircraft", "Search On Aircraft", nullptr));
        updateAircraftModellineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Aircraft Model", nullptr));
        label_14->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Model</span></p></body></html>", nullptr));
        updateAircraftAssignedFlightlineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Assigned Flight Number or Keep it Blank", nullptr));
        label_7->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Assigned Flight</span></p></body></html>", nullptr));
        updateAircraftAvalineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Availability state: 0 For False, 1 For True", nullptr));
        label_6->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Availability</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Maintenance Schedule</span></p></body></html>", nullptr));
        updateAircraftMainSchelineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Maintenance Schedule (DD-MM-YYYY)", nullptr));
        updateAircraftBtn->setText(QCoreApplication::translate("adminMangeAircraft", "Update Aircraft Information", nullptr));
        aircraftTabWidget->setTabText(aircraftTabWidget->indexOf(updateAircraftTab), QCoreApplication::translate("adminMangeAircraft", "\360\237\224\204 Update Aircraft", nullptr));
        removeAircraftGroup->setTitle(QString());
        label_9->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Aircraft ID</span></p></body></html>", nullptr));
        removeAircraftIDlineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Aircraft ID", nullptr));
        removeAircraftBtn->setText(QCoreApplication::translate("adminMangeAircraft", "Remove Aircraft", nullptr));
        aircraftTabWidget->setTabText(aircraftTabWidget->indexOf(removeAircraftTab), QCoreApplication::translate("adminMangeAircraft", "\360\237\227\221 Remove Aircraft", nullptr));
        assignAircraftGroup->setTitle(QString());
        label_10->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Aircraft ID</span></p></body></html>", nullptr));
        assignAircraftIDlineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Aircraft ID", nullptr));
        assignAircraftAssignedFlightlineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Assigned Flight Number or Keep it Blank", nullptr));
        label_11->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Assigned Flight</span></p></body></html>", nullptr));
        assignAircraftBtn->setText(QCoreApplication::translate("adminMangeAircraft", "Assign Aircraft to Flight", nullptr));
        aircraftTabWidget->setTabText(aircraftTabWidget->indexOf(assignAircraftTab), QCoreApplication::translate("adminMangeAircraft", "\360\237\224\227 Assign Aircraft", nullptr));
        maintenanceGroup->setTitle(QString());
        label_12->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Aircraft ID</span></p></body></html>", nullptr));
        scheduleAircraftIDlineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Aircraft ID", nullptr));
        label_16->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Maintenance Schedule</span></p></body></html>", nullptr));
        scheduleAircraftMainSchelineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Maintenance Schedule (DD-MM-YYYY)", nullptr));
        maintenanceBtn->setText(QCoreApplication::translate("adminMangeAircraft", "Schedule Maintenance", nullptr));
        aircraftTabWidget->setTabText(aircraftTabWidget->indexOf(maintenanceTab), QCoreApplication::translate("adminMangeAircraft", "\360\237\224\247 Maintenance", nullptr));
        availabilityGroup->setTitle(QString());
        checkAvaAircraftIDlineEdit->setPlaceholderText(QCoreApplication::translate("adminMangeAircraft", "Enter Aircraft ID", nullptr));
        label_15->setText(QCoreApplication::translate("adminMangeAircraft", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700;\">Aircraft ID</span></p></body></html>", nullptr));
        availabilityBtn->setText(QCoreApplication::translate("adminMangeAircraft", "Check Availability", nullptr));
        aircraftTabWidget->setTabText(aircraftTabWidget->indexOf(availabilityTab), QCoreApplication::translate("adminMangeAircraft", "\342\234\205 Availability", nullptr));
        viewAircraftGroup->setTitle(QString());
        aircraftTabWidget->setTabText(aircraftTabWidget->indexOf(viewAircraftTab), QCoreApplication::translate("adminMangeAircraft", "\342\234\210 View All Aircrafts", nullptr));
        BackToMainMenuBtn->setText(QCoreApplication::translate("adminMangeAircraft", "Back to Main Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminMangeAircraft: public Ui_adminMangeAircraft {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__2A2ADMINMANGEAIRCRAFT_H
