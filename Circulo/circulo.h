#ifndef CIRCULO_H_
#define CIRCULO_H_

#include <iostream>
#include <vector>
using namespace std;

class Circulo{
private:
    double area;
    vector<int> centro;
    vector<int>::iterator vi;
    double raio;
    double calcula_area();
public:
    void setRaio();
    void aumenta_raio();
    void setCentro();
    int getRaio();
    int getArea();
    void getCentro();
};



#endif /* CIRCULO_H_ */