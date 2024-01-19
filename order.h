#ifndef ORDER_H
#define ORDER_H
#include <QDialog>

class Order
{
public:
    Order();
    void ZeroValue();
    uint getSum();
    int getValueOf(int m);
    void calcSumCost(int Mv, int Cv, int Pv, int Nv, int Kv);
    void addToOrder(int t);

private:

    uint sumCost;
    uint MultiCount;
    uint ChainikCount;
    uint PosudaCount;
    uint NoutCount;
    uint KofemolkaCount;
};

#endif // ORDER_H
