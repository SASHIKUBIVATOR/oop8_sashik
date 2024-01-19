#include "mainwindow.h"
#include "verify_window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w_main;
    w_main.show();
    return a.exec();
}
