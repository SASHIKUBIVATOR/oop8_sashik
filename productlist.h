#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H

#include <QDialog>
#include "order.h"
#include "techobject.h"


namespace Ui {
class ProductList;
}

class ProductList : public QDialog
{
    Q_OBJECT

public:

    void setName(QString name);
    QString GetName();
    void SetTable(uint i, uint j);
    explicit ProductList(QWidget *parent = nullptr);
    ~ProductList();
    QString getNameTech();
    void AddToList(TechObject t1);
    void checkT();
    int getSumCost();
    void readFile();
    void WriteCheck();

private slots:
    void on_add1_clicked();

    void on_add2_clicked();

    void on_add3_clicked();

    void on_add4_clicked();

    void on_add5_clicked();

    void on_reset_clicked();

    void on_order_clicked();

private:
    Ui::ProductList *ui;
    QString name;
    QList<TechObject> technika;
    Order check;
};

#endif // PRODUCTLIST_H
