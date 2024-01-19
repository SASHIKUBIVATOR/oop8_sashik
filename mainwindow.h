#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "productlist.h"
#include <QFile>
#include <QByteArray>
#include <QString>
#include "order.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void readFile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    ProductList * product_window;

};
#endif // MAINWINDOW_H
