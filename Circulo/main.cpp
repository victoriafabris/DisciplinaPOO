#include <iostream>
#include <vector>
#include "circulo.h"

using namespace std;

int main(){
    Circulo circulo1;
    circulo1.setRaio();
    circulo1.aumenta_raio();
    cout << "O valor atual do raio do círculo é: " << circulo1.getRaio() << endl;
    cout << "O valor atual da área do círculo é: " << circulo1.getArea() << endl;
    circulo1.setCentro();
    circulo1.getCentro();
    return 0;
}