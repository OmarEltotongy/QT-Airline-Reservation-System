#include "_1_mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon(":/resources/airplane.ico"));

    MainWindow w;
    w.show();
    return a.exec();
}
