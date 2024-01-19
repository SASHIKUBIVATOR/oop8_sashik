#ifndef TECHOBJECT_H
#define TECHOBJECT_H

#include <QString>
#include <tuple>

class TechObject
{
public:
    TechObject();
    TechObject(QString namme, uint costt, uint numm);

    void setName(QString nam);
    void setNumber(uint numb);
    void setCost(uint costt);
    int getCost();
    int getNumber();
    QString getName();


private:
    QString name;
    int cost;
    int number;

};

#endif // TECHOBJECT_H
