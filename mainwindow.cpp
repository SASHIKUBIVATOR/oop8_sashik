#include "mainwindow.h"
#include "techobject.h"
#include "./ui_mainwindow.h"
#include "./ui_productlist.h"
#include "productlist.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    product_window = new ProductList();
    QWidget::setFixedSize(window()->width() , window()->height());
    this->setWindowTitle("Авторизация");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->NickName->text().isEmpty()){
        QMessageBox::information(this,"Ошибка", "Ошибка: неверно введено имя пользователя или строка пуста!");
        return;
    }
    QString userName = ui->NickName->text();
    product_window->setName(userName);
    product_window->show();
    this->close();
    product_window->readFile();
    product_window->checkT();
    product_window->SetTable(5,4);



}






