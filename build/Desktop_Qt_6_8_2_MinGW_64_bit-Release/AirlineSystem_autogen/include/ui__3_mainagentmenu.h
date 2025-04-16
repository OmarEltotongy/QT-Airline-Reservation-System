/********************************************************************************
** Form generated from reading UI file '_3_mainagentmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__3_MAINAGENTMENU_H
#define UI__3_MAINAGENTMENU_H

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

class Ui_mainAgentMenu
{
public:
    QVBoxLayout *mainLayout;
    QLabel *headerLabel;
    QTabWidget *tabWidget;
    QWidget *searchTab;
    QVBoxLayout *searchLayout;
    QGroupBox *searchGroup;
    QFormLayout *searchForm;
    QLabel *originLabel;
    QLineEdit *originInput;
    QLabel *destLabel;
    QLineEdit *destInput;
    QLabel *dateLabel;
    QLineEdit *dateInput;
    QPushButton *searchButton;
    QGroupBox *resultsGroup;
    QVBoxLayout *resultsLayout;
    QTableWidget *flightsTable;
    QWidget *bookTab;
    QVBoxLayout *bookLayout;
    QGroupBox *passengerGroup;
    QFormLayout *passengerForm;
    QLabel *passengerLabel;
    QLineEdit *passengerInput;
    QGroupBox *flightGroup;
    QFormLayout *flightForm;
    QLabel *flightNumLabel;
    QLineEdit *flightNumInput;
    QLabel *seatLabel;
    QLineEdit *seatInput;
    QGroupBox *paymentGroup;
    QHBoxLayout *paymentLayout;
    QRadioButton *walletRadio;
    QRadioButton *paypalRadio;
    QRadioButton *creditRadio;
    QPushButton *bookButton;
    QWidget *modifyTab;
    QVBoxLayout *modifyLayout;
    QGroupBox *modifySearchGroup;
    QFormLayout *modifySearchForm;
    QLabel *modifyUserLabel;
    QLineEdit *modifyUserInput;
    QPushButton *modifySearchButton;
    QGroupBox *modifyResultsGroup;
    QVBoxLayout *modifyResultsLayout;
    QTableWidget *modifyTable;
    QGroupBox *modifyActionGroup;
    QFormLayout *modifyActionForm;
    QLabel *newSeatLabel;
    QLineEdit *newSeatInput;
    QPushButton *modifyButton;
    QWidget *cancelTab;
    QVBoxLayout *cancelLayout;
    QGroupBox *cancelSearchGroup;
    QFormLayout *cancelSearchForm;
    QLabel *cancelUserLabel;
    QLineEdit *cancelUserInput;
    QPushButton *cancelSearchButton;
    QGroupBox *cancelResultsGroup;
    QVBoxLayout *cancelResultsLayout;
    QTableWidget *cancelTable;
    QPushButton *cancelButton;
    QPushButton *logoutButton;

    void setupUi(QDialog *mainAgentMenu)
    {
        if (mainAgentMenu->objectName().isEmpty())
            mainAgentMenu->setObjectName("mainAgentMenu");
        mainAgentMenu->resize(1000, 800);
        mainAgentMenu->setStyleSheet(QString::fromUtf8("\n"
"        QDialog {\n"
"          background-color: #f5f7fa;\n"
"          font-family: 'Segoe UI', Arial, sans-serif;\n"
"        }\n"
"        QTabWidget::pane {\n"
"          border: none;\n"
"        }\n"
"        QTabBar::tab {\n"
"          background: #e1e5eb;\n"
"          color: #2c3e50;\n"
"          padding: 10px 20px;\n"
"          border-top-left-radius: 4px;\n"
"          border-top-right-radius: 4px;\n"
"          margin-right: 2px;\n"
"          font-weight: 500;\n"
"          min-width: 120px;\n"
"        }\n"
"        QTabBar::tab:selected {\n"
"          background: white;\n"
"          border-bottom: 3px solid #3498db;\n"
"          color: #3498db;\n"
"        }\n"
"        QGroupBox {\n"
"          border: 1px solid #d1d9e6;\n"
"          border-radius: 8px;\n"
"          margin: 10px;\n"
"          padding: 15px;\n"
"          background-color: white;\n"
"        }\n"
"        QPushButton {\n"
"          background-color: #3498db;\n"
"          color: white;\n"
"          border: none;"
                        "\n"
"          padding: 10px 16px;\n"
"          border-radius: 6px;\n"
"          margin: 8px;\n"
"          min-width: 180px;\n"
"        }\n"
"        QPushButton:hover {\n"
"          background-color: #2980b9;\n"
"        }\n"
"        QPushButton#logoutButton {\n"
"          background-color: #e74c3c;\n"
"        }\n"
"        QPushButton#logoutButton:hover {\n"
"          background-color: #c0392b;\n"
"        }\n"
"        QLineEdit {\n"
"          padding: 8px;\n"
"          border: 1px solid #d1d9e6;\n"
"          border-radius: 4px;\n"
"        }\n"
"        QTableWidget {\n"
"          border: 1px solid #d1d9e6;\n"
"          background: white;\n"
"        }\n"
"        QHeaderView::section {\n"
"          background-color: #3498db;\n"
"          color: white;\n"
"          padding: 6px;\n"
"        }\n"
"        QLabel#headerLabel {\n"
"          font-size: 24px;\n"
"          font-weight: bold;\n"
"          qproperty-alignment: AlignCenter;\n"
"        }\n"
"      "));
        mainLayout = new QVBoxLayout(mainAgentMenu);
        mainLayout->setObjectName("mainLayout");
        headerLabel = new QLabel(mainAgentMenu);
        headerLabel->setObjectName("headerLabel");

        mainLayout->addWidget(headerLabel);

        tabWidget = new QTabWidget(mainAgentMenu);
        tabWidget->setObjectName("tabWidget");
        searchTab = new QWidget();
        searchTab->setObjectName("searchTab");
        searchLayout = new QVBoxLayout(searchTab);
        searchLayout->setObjectName("searchLayout");
        searchGroup = new QGroupBox(searchTab);
        searchGroup->setObjectName("searchGroup");
        searchForm = new QFormLayout(searchGroup);
        searchForm->setObjectName("searchForm");
        originLabel = new QLabel(searchGroup);
        originLabel->setObjectName("originLabel");

        searchForm->setWidget(0, QFormLayout::LabelRole, originLabel);

        originInput = new QLineEdit(searchGroup);
        originInput->setObjectName("originInput");

        searchForm->setWidget(0, QFormLayout::FieldRole, originInput);

        destLabel = new QLabel(searchGroup);
        destLabel->setObjectName("destLabel");

        searchForm->setWidget(1, QFormLayout::LabelRole, destLabel);

        destInput = new QLineEdit(searchGroup);
        destInput->setObjectName("destInput");

        searchForm->setWidget(1, QFormLayout::FieldRole, destInput);

        dateLabel = new QLabel(searchGroup);
        dateLabel->setObjectName("dateLabel");

        searchForm->setWidget(2, QFormLayout::LabelRole, dateLabel);

        dateInput = new QLineEdit(searchGroup);
        dateInput->setObjectName("dateInput");

        searchForm->setWidget(2, QFormLayout::FieldRole, dateInput);


        searchLayout->addWidget(searchGroup);

        searchButton = new QPushButton(searchTab);
        searchButton->setObjectName("searchButton");

        searchLayout->addWidget(searchButton);

        resultsGroup = new QGroupBox(searchTab);
        resultsGroup->setObjectName("resultsGroup");
        resultsLayout = new QVBoxLayout(resultsGroup);
        resultsLayout->setObjectName("resultsLayout");
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
        flightsTable->setRowCount(0);
        flightsTable->setColumnCount(5);

        resultsLayout->addWidget(flightsTable);


        searchLayout->addWidget(resultsGroup);

        tabWidget->addTab(searchTab, QString());
        bookTab = new QWidget();
        bookTab->setObjectName("bookTab");
        bookLayout = new QVBoxLayout(bookTab);
        bookLayout->setObjectName("bookLayout");
        passengerGroup = new QGroupBox(bookTab);
        passengerGroup->setObjectName("passengerGroup");
        passengerForm = new QFormLayout(passengerGroup);
        passengerForm->setObjectName("passengerForm");
        passengerLabel = new QLabel(passengerGroup);
        passengerLabel->setObjectName("passengerLabel");

        passengerForm->setWidget(0, QFormLayout::LabelRole, passengerLabel);

        passengerInput = new QLineEdit(passengerGroup);
        passengerInput->setObjectName("passengerInput");

        passengerForm->setWidget(0, QFormLayout::FieldRole, passengerInput);


        bookLayout->addWidget(passengerGroup);

        flightGroup = new QGroupBox(bookTab);
        flightGroup->setObjectName("flightGroup");
        flightForm = new QFormLayout(flightGroup);
        flightForm->setObjectName("flightForm");
        flightNumLabel = new QLabel(flightGroup);
        flightNumLabel->setObjectName("flightNumLabel");

        flightForm->setWidget(0, QFormLayout::LabelRole, flightNumLabel);

        flightNumInput = new QLineEdit(flightGroup);
        flightNumInput->setObjectName("flightNumInput");

        flightForm->setWidget(0, QFormLayout::FieldRole, flightNumInput);

        seatLabel = new QLabel(flightGroup);
        seatLabel->setObjectName("seatLabel");

        flightForm->setWidget(1, QFormLayout::LabelRole, seatLabel);

        seatInput = new QLineEdit(flightGroup);
        seatInput->setObjectName("seatInput");

        flightForm->setWidget(1, QFormLayout::FieldRole, seatInput);


        bookLayout->addWidget(flightGroup);

        paymentGroup = new QGroupBox(bookTab);
        paymentGroup->setObjectName("paymentGroup");
        paymentLayout = new QHBoxLayout(paymentGroup);
        paymentLayout->setObjectName("paymentLayout");
        walletRadio = new QRadioButton(paymentGroup);
        walletRadio->setObjectName("walletRadio");
        walletRadio->setChecked(true);

        paymentLayout->addWidget(walletRadio);

        paypalRadio = new QRadioButton(paymentGroup);
        paypalRadio->setObjectName("paypalRadio");

        paymentLayout->addWidget(paypalRadio);

        creditRadio = new QRadioButton(paymentGroup);
        creditRadio->setObjectName("creditRadio");

        paymentLayout->addWidget(creditRadio);


        bookLayout->addWidget(paymentGroup);

        bookButton = new QPushButton(bookTab);
        bookButton->setObjectName("bookButton");

        bookLayout->addWidget(bookButton);

        tabWidget->addTab(bookTab, QString());
        modifyTab = new QWidget();
        modifyTab->setObjectName("modifyTab");
        modifyLayout = new QVBoxLayout(modifyTab);
        modifyLayout->setObjectName("modifyLayout");
        modifySearchGroup = new QGroupBox(modifyTab);
        modifySearchGroup->setObjectName("modifySearchGroup");
        modifySearchForm = new QFormLayout(modifySearchGroup);
        modifySearchForm->setObjectName("modifySearchForm");
        modifyUserLabel = new QLabel(modifySearchGroup);
        modifyUserLabel->setObjectName("modifyUserLabel");

        modifySearchForm->setWidget(0, QFormLayout::LabelRole, modifyUserLabel);

        modifyUserInput = new QLineEdit(modifySearchGroup);
        modifyUserInput->setObjectName("modifyUserInput");

        modifySearchForm->setWidget(0, QFormLayout::FieldRole, modifyUserInput);


        modifyLayout->addWidget(modifySearchGroup);

        modifySearchButton = new QPushButton(modifyTab);
        modifySearchButton->setObjectName("modifySearchButton");

        modifyLayout->addWidget(modifySearchButton);

        modifyResultsGroup = new QGroupBox(modifyTab);
        modifyResultsGroup->setObjectName("modifyResultsGroup");
        modifyResultsLayout = new QVBoxLayout(modifyResultsGroup);
        modifyResultsLayout->setObjectName("modifyResultsLayout");
        modifyTable = new QTableWidget(modifyResultsGroup);
        if (modifyTable->columnCount() < 6)
            modifyTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        modifyTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        modifyTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        modifyTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        modifyTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        modifyTable->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        modifyTable->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        modifyTable->setObjectName("modifyTable");
        modifyTable->setRowCount(0);
        modifyTable->setColumnCount(6);

        modifyResultsLayout->addWidget(modifyTable);


        modifyLayout->addWidget(modifyResultsGroup);

        modifyActionGroup = new QGroupBox(modifyTab);
        modifyActionGroup->setObjectName("modifyActionGroup");
        modifyActionForm = new QFormLayout(modifyActionGroup);
        modifyActionForm->setObjectName("modifyActionForm");
        newSeatLabel = new QLabel(modifyActionGroup);
        newSeatLabel->setObjectName("newSeatLabel");

        modifyActionForm->setWidget(0, QFormLayout::LabelRole, newSeatLabel);

        newSeatInput = new QLineEdit(modifyActionGroup);
        newSeatInput->setObjectName("newSeatInput");

        modifyActionForm->setWidget(0, QFormLayout::FieldRole, newSeatInput);


        modifyLayout->addWidget(modifyActionGroup);

        modifyButton = new QPushButton(modifyTab);
        modifyButton->setObjectName("modifyButton");
        modifyButton->setEnabled(false);

        modifyLayout->addWidget(modifyButton);

        tabWidget->addTab(modifyTab, QString());
        cancelTab = new QWidget();
        cancelTab->setObjectName("cancelTab");
        cancelLayout = new QVBoxLayout(cancelTab);
        cancelLayout->setObjectName("cancelLayout");
        cancelSearchGroup = new QGroupBox(cancelTab);
        cancelSearchGroup->setObjectName("cancelSearchGroup");
        cancelSearchForm = new QFormLayout(cancelSearchGroup);
        cancelSearchForm->setObjectName("cancelSearchForm");
        cancelUserLabel = new QLabel(cancelSearchGroup);
        cancelUserLabel->setObjectName("cancelUserLabel");

        cancelSearchForm->setWidget(0, QFormLayout::LabelRole, cancelUserLabel);

        cancelUserInput = new QLineEdit(cancelSearchGroup);
        cancelUserInput->setObjectName("cancelUserInput");

        cancelSearchForm->setWidget(0, QFormLayout::FieldRole, cancelUserInput);


        cancelLayout->addWidget(cancelSearchGroup);

        cancelSearchButton = new QPushButton(cancelTab);
        cancelSearchButton->setObjectName("cancelSearchButton");

        cancelLayout->addWidget(cancelSearchButton);

        cancelResultsGroup = new QGroupBox(cancelTab);
        cancelResultsGroup->setObjectName("cancelResultsGroup");
        cancelResultsLayout = new QVBoxLayout(cancelResultsGroup);
        cancelResultsLayout->setObjectName("cancelResultsLayout");
        cancelTable = new QTableWidget(cancelResultsGroup);
        if (cancelTable->columnCount() < 6)
            cancelTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        cancelTable->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        cancelTable->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        cancelTable->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        cancelTable->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        cancelTable->setHorizontalHeaderItem(4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        cancelTable->setHorizontalHeaderItem(5, __qtablewidgetitem16);
        cancelTable->setObjectName("cancelTable");
        cancelTable->setRowCount(0);
        cancelTable->setColumnCount(6);

        cancelResultsLayout->addWidget(cancelTable);


        cancelLayout->addWidget(cancelResultsGroup);

        cancelButton = new QPushButton(cancelTab);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setEnabled(false);

        cancelLayout->addWidget(cancelButton);

        tabWidget->addTab(cancelTab, QString());

        mainLayout->addWidget(tabWidget);

        logoutButton = new QPushButton(mainAgentMenu);
        logoutButton->setObjectName("logoutButton");

        mainLayout->addWidget(logoutButton);


        retranslateUi(mainAgentMenu);
        QObject::connect(logoutButton, &QPushButton::clicked, mainAgentMenu, qOverload<>(&QDialog::deleteLater));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainAgentMenu);
    } // setupUi

    void retranslateUi(QDialog *mainAgentMenu)
    {
        mainAgentMenu->setWindowTitle(QCoreApplication::translate("mainAgentMenu", "Airline System - Agent Dashboard", nullptr));
        headerLabel->setText(QCoreApplication::translate("mainAgentMenu", "Agent Dashboard", nullptr));
        originLabel->setText(QCoreApplication::translate("mainAgentMenu", "Origin:", nullptr));
        originInput->setPlaceholderText(QCoreApplication::translate("mainAgentMenu", "Enter departure city", nullptr));
        destLabel->setText(QCoreApplication::translate("mainAgentMenu", "Destination:", nullptr));
        destInput->setPlaceholderText(QCoreApplication::translate("mainAgentMenu", "Enter arrival city", nullptr));
        dateLabel->setText(QCoreApplication::translate("mainAgentMenu", "Date:", nullptr));
        dateInput->setPlaceholderText(QCoreApplication::translate("mainAgentMenu", "YYYY-MM-DD HH:MM", nullptr));
        searchButton->setText(QCoreApplication::translate("mainAgentMenu", "Search Flights", nullptr));
        resultsGroup->setTitle(QCoreApplication::translate("mainAgentMenu", "Available Flights", nullptr));
        QTableWidgetItem *___qtablewidgetitem = flightsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("mainAgentMenu", "Flight #", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = flightsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("mainAgentMenu", "Departure", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = flightsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("mainAgentMenu", "Arrival", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = flightsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("mainAgentMenu", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = flightsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("mainAgentMenu", "Seats", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(searchTab), QCoreApplication::translate("mainAgentMenu", "\360\237\224\215 Search Flights", nullptr));
        passengerGroup->setTitle(QCoreApplication::translate("mainAgentMenu", "Passenger Details", nullptr));
        passengerLabel->setText(QCoreApplication::translate("mainAgentMenu", "Passenger Username:", nullptr));
        passengerInput->setPlaceholderText(QCoreApplication::translate("mainAgentMenu", "Enter passenger username", nullptr));
        flightGroup->setTitle(QCoreApplication::translate("mainAgentMenu", "Flight Details", nullptr));
        flightNumLabel->setText(QCoreApplication::translate("mainAgentMenu", "Flight Number:", nullptr));
        flightNumInput->setPlaceholderText(QCoreApplication::translate("mainAgentMenu", "Enter flight number", nullptr));
        seatLabel->setText(QCoreApplication::translate("mainAgentMenu", "Seat Number:", nullptr));
        seatInput->setPlaceholderText(QCoreApplication::translate("mainAgentMenu", "e.g., 12A, 7C", nullptr));
        paymentGroup->setTitle(QCoreApplication::translate("mainAgentMenu", "Payment Method", nullptr));
        walletRadio->setText(QCoreApplication::translate("mainAgentMenu", "Wallet", nullptr));
        paypalRadio->setText(QCoreApplication::translate("mainAgentMenu", "PayPal", nullptr));
        creditRadio->setText(QCoreApplication::translate("mainAgentMenu", "Credit Card", nullptr));
        bookButton->setText(QCoreApplication::translate("mainAgentMenu", "Confirm Booking", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(bookTab), QCoreApplication::translate("mainAgentMenu", "\342\234\210\357\270\217 Book Flight", nullptr));
        modifySearchGroup->setTitle(QCoreApplication::translate("mainAgentMenu", "Search Reservations", nullptr));
        modifyUserLabel->setText(QCoreApplication::translate("mainAgentMenu", "Passenger Username:", nullptr));
        modifyUserInput->setPlaceholderText(QCoreApplication::translate("mainAgentMenu", "Enter passenger username", nullptr));
        modifySearchButton->setText(QCoreApplication::translate("mainAgentMenu", "Search Reservations", nullptr));
        modifyResultsGroup->setTitle(QCoreApplication::translate("mainAgentMenu", "Reservations", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = modifyTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("mainAgentMenu", "Reservation ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = modifyTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("mainAgentMenu", "Flight #", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = modifyTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("mainAgentMenu", "Passenger", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = modifyTable->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("mainAgentMenu", "Seat", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = modifyTable->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("mainAgentMenu", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = modifyTable->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("mainAgentMenu", "Route", nullptr));
        modifyActionGroup->setTitle(QCoreApplication::translate("mainAgentMenu", "Modify Seat", nullptr));
        newSeatLabel->setText(QCoreApplication::translate("mainAgentMenu", "New Seat Number:", nullptr));
        newSeatInput->setPlaceholderText(QCoreApplication::translate("mainAgentMenu", "Enter new seat number", nullptr));
        modifyButton->setText(QCoreApplication::translate("mainAgentMenu", "Update Seat", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(modifyTab), QCoreApplication::translate("mainAgentMenu", "\342\234\217\357\270\217 Modify", nullptr));
        cancelSearchGroup->setTitle(QCoreApplication::translate("mainAgentMenu", "Search Reservations", nullptr));
        cancelUserLabel->setText(QCoreApplication::translate("mainAgentMenu", "Passenger Username:", nullptr));
        cancelUserInput->setPlaceholderText(QCoreApplication::translate("mainAgentMenu", "Enter passenger username", nullptr));
        cancelSearchButton->setText(QCoreApplication::translate("mainAgentMenu", "Search Reservations", nullptr));
        cancelResultsGroup->setTitle(QCoreApplication::translate("mainAgentMenu", "Reservations", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = cancelTable->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("mainAgentMenu", "Reservation ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = cancelTable->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("mainAgentMenu", "Flight #", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = cancelTable->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("mainAgentMenu", "Passenger", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = cancelTable->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("mainAgentMenu", "Seat", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = cancelTable->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("mainAgentMenu", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = cancelTable->horizontalHeaderItem(5);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("mainAgentMenu", "Route", nullptr));
        cancelButton->setText(QCoreApplication::translate("mainAgentMenu", "Cancel Reservation", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(cancelTab), QCoreApplication::translate("mainAgentMenu", "\342\235\214 Cancel", nullptr));
        logoutButton->setText(QCoreApplication::translate("mainAgentMenu", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainAgentMenu: public Ui_mainAgentMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__3_MAINAGENTMENU_H
