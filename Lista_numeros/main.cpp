#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "numeros.h"

using namespace std;

int main()
{
	Numeros lista1;
	lista1.pega_numeros();
	lista1.imprime();
	lista1.max();
	lista1.min();
	lista1.crescente();
	return 0;
}