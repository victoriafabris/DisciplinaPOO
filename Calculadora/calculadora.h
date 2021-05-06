#ifndef CALCULADORA_H_
#define CALCULADORA_H_
#include <iostream>
#include <math.h>

using namespace std;

class NumeroComplexo{
public:
	int real, imag; //parte real e imaginária do número
	NumeroComplexo(int r, int i);
	NumeroComplexo();
	static void calculo(NumeroComplexo n1, NumeroComplexo n2, char op);

	//sobrecarregando o operador + (definindo um novo comportamento para o operador de soma)
	NumeroComplexo operator+(const NumeroComplexo& obj)
	{
		NumeroComplexo n; //criando objeto n temporário
		n.real = this->real + obj.real;
		n.imag= this->imag + obj.imag;
		return n;
	}

	NumeroComplexo operator-(const NumeroComplexo& obj)
	{
		NumeroComplexo n;
		n.real = this->real - obj.real;
		n.imag = this->imag - obj.imag;
		return n;
	}

	NumeroComplexo operator*(const NumeroComplexo& obj)
	{
		NumeroComplexo n;
		n.real = this->real * obj.real;
		n.imag = this->imag * obj.imag;
		return n;
	}

	NumeroComplexo operator/(const NumeroComplexo& obj)
	{
		NumeroComplexo n;
		n.real = obj.real / this->real;
		n.imag = obj.imag / this->imag;
		return n;
	}
};


#endif /* CALCULADORA_H_ */