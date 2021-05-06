/*Calculadora com operações simples de números complexos utilizando sobrecarga de operadores*/
#include <iostream>
#include <math.h>

#include "calculadora.h"

using namespace std;

int main() {
    NumeroComplexo n1, n2;
    char op;

    cout << "Bem vindo(a)! Esta é uma calculadora simples de números complexos." << endl;
    cout << "Digite o primeiro número no formato: " << endl;
    cout << "partereal parteimaginaria: " << endl;
    cin >> n1.real >> n1.imag;
    cout << "Informe a operação desejada (+, -, * ou /): " << endl;
    cin >> op;
    cout << "Digite o segundo número no mesmo formato: " << endl;
    cin >> n2.real >> n2.imag;

    NumeroComplexo::calculo(n1, n2, op);

	return 0;
}