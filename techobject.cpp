#include "techobject.h"

TechObject::TechObject() {}

TechObject::TechObject(QString namme, uint costt, uint numm){
    name = namme;
    cost = costt;
    number = numm;
}

QString TechObject::getName(){
    return this->name;
}

void TechObject::setName(QString nam){
    this->name = nam;
}

void TechObject::setNumber(uint numb){
    this->number = numb;
}

void TechObject::setCost(uint costt){
    this->cost = costt;
}

int TechObject::getCost(){
    return this->cost;
}

int TechObject::getNumber(){
    return this->number;
}
