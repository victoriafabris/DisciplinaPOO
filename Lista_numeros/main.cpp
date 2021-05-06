/*Código orientado a objetos em C++ utilizado para praticar o uso da biblioteca STL. 
Recebe uma lista de números inteiros. 
Retorna a lista como ela foi dada, retorna o maior e o menor número da lista e retorna a lista em ordem crescente.
*/

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