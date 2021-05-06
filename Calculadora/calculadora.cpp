#include "calculadora.h"

#include <iostream>
#include <math.h>

using namespace std;

NumeroComplexo::NumeroComplexo(int r, int i) //parametros r: parte real e i: parte imaginária
	{
		this->real = r;
		this->imag = i;
	}

NumeroComplexo::NumeroComplexo()
	{
		this->real = 0;	//parte real do número
		this->imag = 0;	//parte imaginária do numero
	}

void NumeroComplexo::calculo(NumeroComplexo n1, NumeroComplexo n2, char op){
	NumeroComplexo n3;
	switch(op){
	case '+':
		n3 = n1+n2;
		cout << "A soma é: " << n3.real << " + (" << n3.imag << ")i" << endl;
		break;
	case '-':
		n3 = n1-n2;
		cout << "A subtração é: " << n3.real  << " + (" << n3.imag << ")i" << endl;
		break;
	case '*':
		n3 = n1*n2;
		cout << "O produto é: " << n3.real << " + (" << n3.imag << ")i" << endl;
		break;
	case '/':
		n3 = n2/n1;
		cout << "A divisão é: " << n3.real << " + (" << n3.imag << ")i" << endl;
		break;
	}
}