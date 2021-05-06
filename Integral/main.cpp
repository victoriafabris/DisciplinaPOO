#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//Classe base - abstrata
class Funcao {
public:
	Funcao(Funcao* f): _f(f) {}
	Funcao(): _f(0){}
	virtual double operator()(double x) = 0;
	static double integrar(Funcao* f, double x0, double x1, double step);
	virtual ~Funcao(){}
protected:
	Funcao* _f;
};

double Funcao::integrar(Funcao* f, double x0, double x1, double step)
{
	double x, area=0;
	for(x = x0; x <= x1; x = x + step){
		area = area + (*f)(x)*step; //valor da função * step
	}
	return area;
}

//Classes derivadas - concretas
class Constante: public Funcao{
public:
	Constante(double val): value(val) {}
	double operator()(double x)
	{
		return value;
	}
private:
	double value;
};

class Seno: public Funcao{
public:
	Seno(Funcao* f)
	{
		_f = f;
	}
	Seno();
	double operator()(double x)
	{
		if(_f)
		{
			x = (*_f)(x);
		}
		return sin(x);
	}
};

class Cosseno: public Funcao{
	Cosseno(Funcao* f)
	{
			_f = f;
	}
	Cosseno();
	double operator()(double x)
	{
		if(_f)
		{
			x = (*_f)(x);
		}
		return cos(x);
	}
};

class Escalar: public Funcao{
public:
	Escalar(double val, Funcao* f)
	{
		_f = f;
		value = val;
	}
	Escalar(Funcao* f)
	{
		_f = f;
	}
	Escalar(double val){
		value = val;
	}
	Escalar();
	double operator()(double x)
	{
		if(_f)
		{
			x = (*_f)(x);
		}
		return value*x;
	}
private:
	double value;
};

class Potencial: public Funcao{
public:
	Potencial(double val, Funcao* f)
	{
		_f = f;
		value = val;
	}
	Potencial(Funcao* f)
	{
		_f = f;
	}
	Potencial(double val): value(val){
		value = val;
	}
	Potencial();
	double operator()(double x)
	{
		if(_f)
		{
			x = (*_f)(x);
		}
		return pow(x, value);
	}
private:
	double value;
};

class Exponencial: public Funcao{
public:
	Exponencial(double val, Funcao* f)
	{
		_f = f;
		value = val;
	}
	Exponencial(Funcao* f)
	{
		_f = f;
	}
	Exponencial(double val){
		value = val;
	}
	Exponencial();
	double operator()(double x)
	{
		if(_f)
		{
			x = (*_f)(x);
		}
		return pow(value, x);
	}

private:
	double value;
};

class FuncaoAgregada: public Funcao{	//somatório de funções
public:
	FuncaoAgregada(Funcao* f){};
	FuncaoAgregada(){};
	vector<Funcao*> funcao_agregada; //criando vetor p função agregada
	void agrega(Funcao* f)
	{
		funcao_agregada.push_back(f); //armazenando valores das funções na função agregada
	}
	double operator()(double x){
		double z=0;
		for(Funcao* w:funcao_agregada)
		{
			z = z + (*w)(x);
		}
		return z;
	}
};

int main(void) {
	// chama funções
	Potencial g(2); 				// g(x) = x^2;
	FuncaoAgregada j;
	j.agrega(new Escalar(2));
	j.agrega( new Constante(-1));
	Escalar h(5, new Seno(&j));		// h(x) = 5sen(2x-1);
	Constante i(5); 				// i(x) = 5;
	FuncaoAgregada f; 				// f(x) = g(x) + h(x) + i(x)

	// agrega os valores resultantes das funções acima e insere em f
	f.agrega(&g);
	f.agrega(&h);
	f.agrega(&i);

	double x = 0;
	while (x < 5) 	// 0,5 é o intervalo de integração
	{
		cout << "f(" << x << ") = " << f(x) << endl;
		x += 0.01;	// 0,01 é o intervalo de discretização
	}

	cout << "A integral de [0,5] é: ";
	cout << Funcao::integrar(&f,0,5,0.01) << endl;
	return 0;
}







