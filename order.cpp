#include "order.h"
#include "productlist.h"


Order::Order() {        MultiCount=0;
    ChainikCount=0;
    PosudaCount=0;
    NoutCount=0;
    KofemolkaCount=0;
    sumCost = 0;
}



void Order::ZeroValue(){
        MultiCount=0;
        ChainikCount=0;
        PosudaCount=0;
        NoutCount=0;
        KofemolkaCount=0;
}

uint Order::getSum(){
    return this->sumCost;
}

int Order::getValueOf(int m){
    if(m == 0)
        return MultiCount;
    if(m == 1)
        return ChainikCount;
    if(m == 2)
       return PosudaCount;
    if(m == 3)
        return NoutCount;
    if(m == 4)
        return KofemolkaCount;
    else return 0;
}

void Order::calcSumCost(int Mv, int Cv, int Pv, int Nv, int Kv){

    sumCost+=MultiCount*Mv + ChainikCount*Cv + PosudaCount*Pv + NoutCount* Nv + KofemolkaCount* Kv;
}
void Order::addToOrder(int t){
    if(t == 0)
        MultiCount++;
    if(t == 1)
        ChainikCount++;
    if(t == 2)
        PosudaCount++;
    if(t == 3)
        NoutCount++;
    if(t == 4)
        KofemolkaCount++;

}


