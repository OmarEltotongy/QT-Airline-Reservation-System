/********************************************************************************
** Form generated from reading UI file '_4_mainpassengermenu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__4_MAINPASSENGERMENU_H
#define UI__4_MAINPASSENGERMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainPassengerMenu
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *headerLabel;
    QTabWidget *passengerTabWidget;
    QWidget *searchFlightTab;
    QVBoxLayout *searchFlightLayout;
    QGroupBox *searchGroup;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *originLabel;
    QLineEdit *searchOriginLineEdit;
    QLabel *destinationLabel;
    QLineEdit *searchDestinationLineEdit;
    QLabel *dateLabel;
    QLineEdit *searchDateLineEdit;
    QPushButton *searchFlightsBtn;
    QGroupBox *resultsGroup;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *flightsTable;
    QHBoxLayout *horizontalLayout;
    QPushButton *backToSearchBtn;
    QPushButton *selectFlightBtn;
    QWidget *bookFlightTab;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *bookFlightGroup;
    QVBoxLayout *verticalLayout_8;
    QFormLayout *formLayout_2;
    QLabel *flightNumberLabel;
    QLineEdit *bookFlightNumberLineEdit;
    QLabel *seatNumberLabel;
    QLineEdit *bookSeatNumberLineEdit;
    QGroupBox *paymentGroup;
    QVBoxLayout *verticalLayout_9;
    QRadioButton *walletRadioButton;
    QRadioButton *paypalRadioButton;
    QRadioButton *creditcardRadioButton;
    QPushButton *BookTheFlightBtn;
    QWidget *reservationsTab;
    QVBoxLayout *reservationsLayout;
    QGroupBox *reservationsGroup;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_3;
    QLabel *passengerIDLabel;
    QLineEdit *viewUsernameLineEdit;
    QPushButton *viewReservationsBtn;
    QGroupBox *reservationsResultsGroup;
    QVBoxLayout *verticalLayout_10;
    QTableWidget *reservationsTable;
    QWidget *checkInTab;
    QVBoxLayout *checkInLayout;
    QGroupBox *checkInGroup;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout_4;
    QLabel *reservationIDLabel;
    QLineEdit *checkINReservationIDLineEdit;
    QPushButton *checkInBtn;
    QPushButton *logoutBtn;

    void setupUi(QDialog *mainPassengerMenu)
    {
        if (mainPassengerMenu->objectName().isEmpty())
            mainPassengerMenu->setObjectName("mainPassengerMenu");
        mainPassengerMenu->resize(925, 925);
        mainPassengerMenu->setMinimumSize(QSize(800, 650));
        mainPassengerMenu->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #f5f7fa;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}\n"
"QTabWidget {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"QTabBar::tab {\n"
"    background: #e1e5eb;\n"
"    color: #2c3e50;\n"
"    padding: 10px 20px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    margin-right: 4px;\n"
"    font-weight: 500;\n"
"    min-width: 120px;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background: white;\n"
"    border-bottom: 3px solid #3498db;\n"
"    color: #3498db;\n"
"}\n"
"QTabBar::tab:hover {\n"
"    background: #d6e0f0;\n"
"}\n"
"QGroupBox {\n"
"    border: 1px solid #d1d9e6;\n"
"    border-radius: 8px;\n"
"    margin: 10px;\n"
"    padding: 15px;\n"
"    background-color: white;\n"
"    font-size: 14px;\n"
"    color: #2c3e50;\n"
"}\n"
"QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 10px 20px;\n"
"    border-radius: 6px;\n"
"    margin: 8px;\n"
"    fon"
                        "t-size: 14px;\n"
"    font-weight: 500;\n"
"    min-width: 180px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #2472a4;\n"
"}\n"
"QPushButton#logoutBtn {\n"
"    background-color: #e74c3c;\n"
"}\n"
"QPushButton#logoutBtn:hover {\n"
"    background-color: #c0392b;\n"
"}\n"
"QPushButton#logoutBtn:pressed {\n"
"    background-color: #a52714;\n"
"}\n"
"QLabel#headerLabel {\n"
"    font-size: 24px;\n"
"    font-weight: 600;\n"
"    color: #2c3e50;\n"
"    qproperty-alignment: AlignCenter;\n"
"    margin: 15px 0;\n"
"}\n"
"QLineEdit {\n"
"    padding: 8px;\n"
"    border: 1px solid #d1d9e6;\n"
"    border-radius: 4px;\n"
"    min-width: 250px;\n"
"}\n"
"QRadioButton {\n"
"    padding: 6px;\n"
"}\n"
"QTableWidget {\n"
"    border: 1px solid #d1d9e6;\n"
"    border-radius: 4px;\n"
"    background: white;\n"
"    selection-background-color: #e1f0fa;\n"
"    selection-color: #2c3e50;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #"
                        "3498db;\n"
"    color: white;\n"
"    padding: 6px;\n"
"    border: none;\n"
"}"));
        verticalLayout = new QVBoxLayout(mainPassengerMenu);
        verticalLayout->setObjectName("verticalLayout");
        headerLabel = new QLabel(mainPassengerMenu);
        headerLabel->setObjectName("headerLabel");

        verticalLayout->addWidget(headerLabel);

        passengerTabWidget = new QTabWidget(mainPassengerMenu);
        passengerTabWidget->setObjectName("passengerTabWidget");
        searchFlightTab = new QWidget();
        searchFlightTab->setObjectName("searchFlightTab");
        searchFlightLayout = new QVBoxLayout(searchFlightTab);
        searchFlightLayout->setObjectName("searchFlightLayout");
        searchGroup = new QGroupBox(searchFlightTab);
        searchGroup->setObjectName("searchGroup");
        verticalLayout_2 = new QVBoxLayout(searchGroup);
        verticalLayout_2->setObjectName("verticalLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        originLabel = new QLabel(searchGroup);
        originLabel->setObjectName("originLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, originLabel);

        searchOriginLineEdit = new QLineEdit(searchGroup);
        searchOriginLineEdit->setObjectName("searchOriginLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, searchOriginLineEdit);

        destinationLabel = new QLabel(searchGroup);
        destinationLabel->setObjectName("destinationLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, destinationLabel);

        searchDestinationLineEdit = new QLineEdit(searchGroup);
        searchDestinationLineEdit->setObjectName("searchDestinationLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, searchDestinationLineEdit);

        dateLabel = new QLabel(searchGroup);
        dateLabel->setObjectName("dateLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, dateLabel);

        searchDateLineEdit = new QLineEdit(searchGroup);
        searchDateLineEdit->setObjectName("searchDateLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, searchDateLineEdit);


        verticalLayout_2->addLayout(formLayout);

        searchFlightsBtn = new QPushButton(searchGroup);
        searchFlightsBtn->setObjectName("searchFlightsBtn");

        verticalLayout_2->addWidget(searchFlightsBtn);


        searchFlightLayout->addWidget(searchGroup);

        resultsGroup = new QGroupBox(searchFlightTab);
        resultsGroup->setObjectName("resultsGroup");
        verticalLayout_7 = new QVBoxLayout(resultsGroup);
        verticalLayout_7->setObjectName("verticalLayout_7");
        flightsTable = new QTableWidget(resultsGroup);
        if (flightsTable->columnCount() < 5)
            flightsTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        flightsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        flightsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        flightsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        flightsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        flightsTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        flightsTable->setObjectName("flightsTable");
        flightsTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        flightsTable->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        flightsTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout_7->addWidget(flightsTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        backToSearchBtn = new QPushButton(resultsGroup);
        backToSearchBtn->setObjectName("backToSearchBtn");
        backToSearchBtn->setEnabled(false);

        horizontalLayout->addWidget(backToSearchBtn);

        selectFlightBtn = new QPushButton(resultsGroup);
        selectFlightBtn->setObjectName("selectFlightBtn");
        selectFlightBtn->setEnabled(false);

        horizontalLayout->addWidget(selectFlightBtn);


        verticalLayout_7->addLayout(horizontalLayout);


        searchFlightLayout->addWidget(resultsGroup);

        passengerTabWidget->addTab(searchFlightTab, QString());
        bookFlightTab = new QWidget();
        bookFlightTab->setObjectName("bookFlightTab");
        verticalLayout_6 = new QVBoxLayout(bookFlightTab);
        verticalLayout_6->setObjectName("verticalLayout_6");
        bookFlightGroup = new QGroupBox(bookFlightTab);
        bookFlightGroup->setObjectName("bookFlightGroup");
        verticalLayout_8 = new QVBoxLayout(bookFlightGroup);
        verticalLayout_8->setObjectName("verticalLayout_8");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        flightNumberLabel = new QLabel(bookFlightGroup);
        flightNumberLabel->setObjectName("flightNumberLabel");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, flightNumberLabel);

        bookFlightNumberLineEdit = new QLineEdit(bookFlightGroup);
        bookFlightNumberLineEdit->setObjectName("bookFlightNumberLineEdit");
        bookFlightNumberLineEdit->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, bookFlightNumberLineEdit);

        seatNumberLabel = new QLabel(bookFlightGroup);
        seatNumberLabel->setObjectName("seatNumberLabel");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, seatNumberLabel);

        bookSeatNumberLineEdit = new QLineEdit(bookFlightGroup);
        bookSeatNumberLineEdit->setObjectName("bookSeatNumberLineEdit");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, bookSeatNumberLineEdit);


        verticalLayout_8->addLayout(formLayout_2);


        verticalLayout_6->addWidget(bookFlightGroup);

        paymentGroup = new QGroupBox(bookFlightTab);
        paymentGroup->setObjectName("paymentGroup");
        verticalLayout_9 = new QVBoxLayout(paymentGroup);
        verticalLayout_9->setObjectName("verticalLayout_9");
        walletRadioButton = new QRadioButton(paymentGroup);
        walletRadioButton->setObjectName("walletRadioButton");
        walletRadioButton->setChecked(true);

        verticalLayout_9->addWidget(walletRadioButton);

        paypalRadioButton = new QRadioButton(paymentGroup);
        paypalRadioButton->setObjectName("paypalRadioButton");

        verticalLayout_9->addWidget(paypalRadioButton);

        creditcardRadioButton = new QRadioButton(paymentGroup);
        creditcardRadioButton->setObjectName("creditcardRadioButton");

        verticalLayout_9->addWidget(creditcardRadioButton);


        verticalLayout_6->addWidget(paymentGroup);

        BookTheFlightBtn = new QPushButton(bookFlightTab);
        BookTheFlightBtn->setObjectName("BookTheFlightBtn");

        verticalLayout_6->addWidget(BookTheFlightBtn);

        passengerTabWidget->addTab(bookFlightTab, QString());
        reservationsTab = new QWidget();
        reservationsTab->setObjectName("reservationsTab");
        reservationsLayout = new QVBoxLayout(reservationsTab);
        reservationsLayout->setObjectName("reservationsLayout");
        reservationsGroup = new QGroupBox(reservationsTab);
        reservationsGroup->setObjectName("reservationsGroup");
        verticalLayout_3 = new QVBoxLayout(reservationsGroup);
        verticalLayout_3->setObjectName("verticalLayout_3");
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        passengerIDLabel = new QLabel(reservationsGroup);
        passengerIDLabel->setObjectName("passengerIDLabel");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, passengerIDLabel);

        viewUsernameLineEdit = new QLineEdit(reservationsGroup);
        viewUsernameLineEdit->setObjectName("viewUsernameLineEdit");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, viewUsernameLineEdit);


        verticalLayout_3->addLayout(formLayout_3);

        viewReservationsBtn = new QPushButton(reservationsGroup);
        viewReservationsBtn->setObjectName("viewReservationsBtn");

        verticalLayout_3->addWidget(viewReservationsBtn);


        reservationsLayout->addWidget(reservationsGroup);

        reservationsResultsGroup = new QGroupBox(reservationsTab);
        reservationsResultsGroup->setObjectName("reservationsResultsGroup");
        verticalLayout_10 = new QVBoxLayout(reservationsResultsGroup);
        verticalLayout_10->setObjectName("verticalLayout_10");
        reservationsTable = new QTableWidget(reservationsResultsGroup);
        if (reservationsTable->columnCount() < 6)
            reservationsTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        reservationsTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        reservationsTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        reservationsTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        reservationsTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        reservationsTable->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        reservationsTable->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        reservationsTable->setObjectName("reservationsTable");

        verticalLayout_10->addWidget(reservationsTable);


        reservationsLayout->addWidget(reservationsResultsGroup);

        passengerTabWidget->addTab(reservationsTab, QString());
        checkInTab = new QWidget();
        checkInTab->setObjectName("checkInTab");
        checkInLayout = new QVBoxLayout(checkInTab);
        checkInLayout->setObjectName("checkInLayout");
        checkInGroup = new QGroupBox(checkInTab);
        checkInGroup->setObjectName("checkInGroup");
        verticalLayout_4 = new QVBoxLayout(checkInGroup);
        verticalLayout_4->setObjectName("verticalLayout_4");
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        reservationIDLabel = new QLabel(checkInGroup);
        reservationIDLabel->setObjectName("reservationIDLabel");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, reservationIDLabel);

        checkINReservationIDLineEdit = new QLineEdit(checkInGroup);
        checkINReservationIDLineEdit->setObjectName("checkINReservationIDLineEdit");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, checkINReservationIDLineEdit);


        verticalLayout_4->addLayout(formLayout_4);

        checkInBtn = new QPushButton(checkInGroup);
        checkInBtn->setObjectName("checkInBtn");

        verticalLayout_4->addWidget(checkInBtn);


        checkInLayout->addWidget(checkInGroup);

        passengerTabWidget->addTab(checkInTab, QString());

        verticalLayout->addWidget(passengerTabWidget);

        logoutBtn = new QPushButton(mainPassengerMenu);
        logoutBtn->setObjectName("logoutBtn");

        verticalLayout->addWidget(logoutBtn);


        retranslateUi(mainPassengerMenu);
        QObject::connect(logoutBtn, &QPushButton::clicked, mainPassengerMenu, qOverload<>(&QDialog::deleteLater));

        passengerTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainPassengerMenu);
    } // setupUi

    void retranslateUi(QDialog *mainPassengerMenu)
    {
        mainPassengerMenu->setWindowTitle(QCoreApplication::translate("mainPassengerMenu", "Airline System - Passenger Dashboard", nullptr));
        headerLabel->setText(QCoreApplication::translate("mainPassengerMenu", "Passenger Dashboard", nullptr));
        searchGroup->setTitle(QCoreApplication::translate("mainPassengerMenu", "Search Flights", nullptr));
        originLabel->setText(QCoreApplication::translate("mainPassengerMenu", "Origin:", nullptr));
        searchOriginLineEdit->setPlaceholderText(QCoreApplication::translate("mainPassengerMenu", "Enter departure city/airport", nullptr));
        destinationLabel->setText(QCoreApplication::translate("mainPassengerMenu", "Destination:", nullptr));
        searchDestinationLineEdit->setPlaceholderText(QCoreApplication::translate("mainPassengerMenu", "Enter arrival city/airport", nullptr));
        dateLabel->setText(QCoreApplication::translate("mainPassengerMenu", "Date:", nullptr));
        searchDateLineEdit->setPlaceholderText(QCoreApplication::translate("mainPassengerMenu", "YYYY-MM-DD HH:MM", nullptr));
        searchFlightsBtn->setText(QCoreApplication::translate("mainPassengerMenu", "Search Flights", nullptr));
        resultsGroup->setTitle(QCoreApplication::translate("mainPassengerMenu", "Available Flights", nullptr));
        QTableWidgetItem *___qtablewidgetitem = flightsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("mainPassengerMenu", "Flight #", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = flightsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("mainPassengerMenu", "Origin", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = flightsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("mainPassengerMenu", "Destination", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = flightsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("mainPassengerMenu", "Departure", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = flightsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("mainPassengerMenu", "Price", nullptr));
        backToSearchBtn->setText(QCoreApplication::translate("mainPassengerMenu", "Back to Search", nullptr));
        selectFlightBtn->setText(QCoreApplication::translate("mainPassengerMenu", "Select Flight", nullptr));
        passengerTabWidget->setTabText(passengerTabWidget->indexOf(searchFlightTab), QCoreApplication::translate("mainPassengerMenu", "\360\237\224\215 Search & Book Flight", nullptr));
        bookFlightGroup->setTitle(QCoreApplication::translate("mainPassengerMenu", "Flight Details", nullptr));
        flightNumberLabel->setText(QCoreApplication::translate("mainPassengerMenu", "Flight Number:", nullptr));
        seatNumberLabel->setText(QCoreApplication::translate("mainPassengerMenu", "Seat Number:", nullptr));
        bookSeatNumberLineEdit->setPlaceholderText(QCoreApplication::translate("mainPassengerMenu", "e.g., 12A, 7C, etc.", nullptr));
        paymentGroup->setTitle(QCoreApplication::translate("mainPassengerMenu", "Payment Method", nullptr));
        walletRadioButton->setText(QCoreApplication::translate("mainPassengerMenu", "Wallet", nullptr));
        paypalRadioButton->setText(QCoreApplication::translate("mainPassengerMenu", "PayPal", nullptr));
        creditcardRadioButton->setText(QCoreApplication::translate("mainPassengerMenu", "Credit Card", nullptr));
        BookTheFlightBtn->setText(QCoreApplication::translate("mainPassengerMenu", "Confirm Booking", nullptr));
        passengerTabWidget->setTabText(passengerTabWidget->indexOf(bookFlightTab), QCoreApplication::translate("mainPassengerMenu", "\342\234\210\357\270\217 Book Flight", nullptr));
        reservationsGroup->setTitle(QCoreApplication::translate("mainPassengerMenu", "View Reservations", nullptr));
        passengerIDLabel->setText(QCoreApplication::translate("mainPassengerMenu", "Passenger ID:", nullptr));
        viewUsernameLineEdit->setPlaceholderText(QCoreApplication::translate("mainPassengerMenu", "Enter your passenger ID", nullptr));
        viewReservationsBtn->setText(QCoreApplication::translate("mainPassengerMenu", "View Reservations", nullptr));
        reservationsResultsGroup->setTitle(QCoreApplication::translate("mainPassengerMenu", "Your Reservations", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = reservationsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("mainPassengerMenu", "Reservation ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = reservationsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("mainPassengerMenu", "Flight #", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = reservationsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("mainPassengerMenu", "Route", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = reservationsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("mainPassengerMenu", "Departure", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = reservationsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("mainPassengerMenu", "Seat", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = reservationsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("mainPassengerMenu", "Status", nullptr));
        passengerTabWidget->setTabText(passengerTabWidget->indexOf(reservationsTab), QCoreApplication::translate("mainPassengerMenu", "\360\237\223\213 My Reservations", nullptr));
        checkInGroup->setTitle(QCoreApplication::translate("mainPassengerMenu", "Check-In for Flight", nullptr));
        reservationIDLabel->setText(QCoreApplication::translate("mainPassengerMenu", "Reservation ID:", nullptr));
        checkINReservationIDLineEdit->setPlaceholderText(QCoreApplication::translate("mainPassengerMenu", "Enter your reservation ID", nullptr));
        checkInBtn->setText(QCoreApplication::translate("mainPassengerMenu", "Check-In", nullptr));
        passengerTabWidget->setTabText(passengerTabWidget->indexOf(checkInTab), QCoreApplication::translate("mainPassengerMenu", "\360\237\233\253 Check-In", nullptr));
        logoutBtn->setText(QCoreApplication::translate("mainPassengerMenu", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainPassengerMenu: public Ui_mainPassengerMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__4_MAINPASSENGERMENU_H
