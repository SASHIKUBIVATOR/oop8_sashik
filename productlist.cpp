#include "productlist.h"
#include "order.h"
#include "ui_productlist.h"
#include <QDebug>
#include <QMessageBox>
#include <string>
#include <QDebug>
#include <fstream>
#include <QFile>

ProductList::ProductList(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProductList)
{
    ui->setupUi(this);
}

ProductList::~ProductList()
{
    delete ui;
}

void ProductList::setName(QString name){
    this->name = name;
}

void ProductList::AddToList(TechObject t1){
    this->technika.push_back(t1);
}

int ProductList::getSumCost(){
    return this->check.getSum();
}

QString ProductList::getNameTech(){
    return this->technika[1].getName();
}

void ProductList::checkT(){
    this->check = Order();
}

QString ProductList::GetName(){
    return this->name;
}

void ProductList::on_add1_clicked()
{
    if(technika[0].getCost()!=0){
    check.addToOrder(0);
    QTableWidgetItem *item  = new QTableWidgetItem(QString::number(this->check.getValueOf(0)));   //установка элемента
    ui->gadgetsTable->setItem(0,3,item);
    technika[0].setCost(technika[0].getCost()-1);
    QTableWidgetItem *item2  = new QTableWidgetItem(QString::number(technika[0].getCost()));
    ui->gadgetsTable->setItem(0,1,item2);
    } else {
        QMessageBox::information(this,"Упс", "В магазине закончились товары))");
        return;
    }
}


void ProductList::on_add2_clicked()
{
    if(technika[1].getCost()!=0){
        check.addToOrder(1);
        QTableWidgetItem *item  = new QTableWidgetItem(QString::number(this->check.getValueOf(1)));   //установка элемента
        ui->gadgetsTable->setItem(1,3,item);
        technika[1].setCost(technika[1].getCost()-1);
        QTableWidgetItem *item2  = new QTableWidgetItem(QString::number(technika[1].getCost()));
        ui->gadgetsTable->setItem(1,1,item2);
    } else {
        QMessageBox::information(this,"Упс", "В магазине закончились товары))");
        return;
    }
}


void ProductList::on_add3_clicked()
{
    if(technika[2].getCost()!=0){
        check.addToOrder(2);
        QTableWidgetItem *item  = new QTableWidgetItem(QString::number(this->check.getValueOf(2)));   //установка элемента
        ui->gadgetsTable->setItem(2,3,item);
        technika[2].setCost(technika[2].getCost()-1);
        QTableWidgetItem *item2  = new QTableWidgetItem(QString::number(technika[2].getCost()));
        ui->gadgetsTable->setItem(2,1,item2);
    } else {
        QMessageBox::information(this,"Упс", "В магазине закончились товары))");
        return;
    }
}


void ProductList::on_add4_clicked()
{
    if(technika[3].getCost()!=0){
        check.addToOrder(3);
        QTableWidgetItem *item  = new QTableWidgetItem(QString::number(this->check.getValueOf(3)));   //установка элемента
        ui->gadgetsTable->setItem(3,3,item);
        technika[3].setCost(technika[3].getCost()-1);
        QTableWidgetItem *item2  = new QTableWidgetItem(QString::number(technika[3].getCost()));
        ui->gadgetsTable->setItem(3,1,item2);
    } else {
        QMessageBox::information(this,"Упс", "В магазине закончились товары))");
        return;
    }
}


void ProductList::on_add5_clicked()
{
    if(technika[4].getCost()!=0){
        check.addToOrder(4);
        QTableWidgetItem *item  = new QTableWidgetItem(QString::number(this->check.getValueOf(4)));   //установка элемента
        ui->gadgetsTable->setItem(4,3,item);
        technika[4].setCost(technika[4].getCost()-1);
        QTableWidgetItem *item2  = new QTableWidgetItem(QString::number(technika[4].getCost()));
        ui->gadgetsTable->setItem(4,1,item2);
    } else {
        QMessageBox::information(this,"Упс", "В магазине закончились товары))");
        return;
    }
}


void ProductList::on_reset_clicked()
{
    check.ZeroValue();
    technika.clear();
    readFile();
    SetTable(5,4);
    QMessageBox::information(this,"Изменения", "Вы опустошили корзину!");


}


void ProductList::on_order_clicked()
{
      WriteCheck();
      this->close();
}

void ProductList::SetTable(uint i, uint j){
    ui->gadgetsTable->setRowCount(i);
    ui->gadgetsTable->setColumnCount(j);
    ui->gadgetsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setWindowTitle("Магазин");
    ui->gadgetsTable->setHorizontalHeaderLabels(QStringList() << "Предмет" << "Кол-во штук" << "Цена" << "Кол-во (заказать)");
    for(int k = 0; k < i ; k++ ){
        ui->gadgetsTable->setColumnWidth(k,132);
        ui->gadgetsTable->setRowHeight(k,62);
        //QTableWidgetItem *item  = new QTableWidgetItem("Huinya!");   //установка элемента
       // ui->gadgetsTable->setItem(1,1,item);
       // QString tt =  ui->gadgetsTable->item(1,1)->text();       //забрать элемент
    }

        for(int g = 0;g < i;g++){
            auto h = this->technika[g].getName();
            QTableWidgetItem *item  = new QTableWidgetItem(h);
            ui->gadgetsTable->setItem(g,0,item);
         }

        for(int g = 0;g < i;g++){
            auto h = this->technika[g].getCost();
            QTableWidgetItem *item  = new QTableWidgetItem(QString::number(h));
            ui->gadgetsTable->setItem(g,1,item);
        }

        for(int g = 0;g < i;g++){
            auto h = this->technika[g].getNumber();
            QTableWidgetItem *item  = new QTableWidgetItem(QString::number(h));
            ui->gadgetsTable->setItem(g,2,item);
        }

        for(int g = 0;g < i;g++){
            QTableWidgetItem *item  = new QTableWidgetItem(QString::number(0));
            ui->gadgetsTable->setItem(g,3,item);
        }


}

void ProductList::readFile(){
    QString str;
    QString Data_str;
    TechObject t;
    QFile file("C:/Users/Kira/Documents/IDZ_TECHZONE/IDZ_OOP_TECHZONE/products.txt"); // создаем объект класса QFile
    //if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
    //  return; // если это сделать невозможно, то завершаем функцию


    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {

            str = file.readLine();
            int j = 0;
            while(str[j]!='$'){
                Data_str+=str[j];
                j++;
            }
            j++;
            t.setName(Data_str);
            Data_str = "";
            while(str[j]!='/'){
                Data_str+=str[j];
                j++;
            }
            j++;
            t.setCost(Data_str.toInt());
            Data_str = "";
            while(j<str.size()){
                Data_str+=str[j];
                j++;
            }
            t.setNumber(Data_str.toInt());
            Data_str = "";
            AddToList(t);



        }
    }
    else
    {
        qDebug() << "Error file read!";
    }
}

void ProductList::WriteCheck(){
    QString str;
    QString Data_str;
    TechObject t;
    QFile file("C:/Users/Kira/Documents/IDZ_TECHZONE/IDZ_OOP_TECHZONE/check.txt"); // создаем объект класса QFile
    //if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
    //  return; // если это сделать невозможно, то завершаем функцию


    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        QTextStream stream(&file);
        stream << "Username: "<< GetName() << "\n";
        QString tt ;
        stream<<"Your check:"<<"\n\n";
        for(int i = 0; i < 5;i++){
        stream<<technika[i].getName()<<"  ##Count:  "<<check.getValueOf(i)<<"  ##Price = "<<check.getValueOf(i)*(int)technika[i].getNumber()<<"\n";
        }
        check.calcSumCost(technika[0].getNumber(),technika[1].getNumber(),technika[2].getNumber(),technika[3].getNumber(),technika[4].getNumber());
        stream << "Itogo = "<< QString::number(getSumCost()) << "\n";

    }
    else
    {
        qDebug() << "Error file read!";
    }
    file.close();

    QMessageBox::information(this,"Чек", "Вы заказали следующие товары:\n" +
    technika[0].getName() + " в кол-ве " + QString::number(check.getValueOf(0)) + "\n" +
    technika[1].getName() + " в кол-ве " + QString::number(check.getValueOf(1)) + "\n" +
    technika[2].getName() + " в кол-ве " + QString::number(check.getValueOf(2)) + "\n" +
    technika[3].getName() + " в кол-ве " + QString::number(check.getValueOf(3)) + "\n" +
    technika[4].getName() + " в кол-ве " + QString::number(check.getValueOf(4)) + "\n" +
    "\nДетали заказа помещены в файл check.txt"
                             );

}

