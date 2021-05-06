#ifndef NUMEROS_H_
#define NUMEROS_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Numeros
{
public:
	void pega_numeros();
	void max();
	void min();
	void crescente();
	void imprime();
	vector<int> lista;
	vector<int>::iterator vi;
};




#endif /* NUMEROS_H_ */