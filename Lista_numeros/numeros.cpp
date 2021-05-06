#include "numeros.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void Numeros::pega_numeros()
{
	int decisao = 1;
	int value;
	string aux;
	int aux_size;
	while (decisao == 1){
		cout << "Por favor, insira um número inteiro:" << endl;
		do {
			getline(cin, aux);
			aux_size = aux.size();
			for(int i = 0; i < aux_size; i++){
				if(!(isdigit(aux[i]))){ //checa se string recebida possui somente numeros de 0 a 9
					aux_size = 0;
					cout << "Por favor, insira somente números inteiros!" << endl;
				}
			}
		} while(aux_size == 0);
		stringstream(aux) >> value;

		lista.push_back(value);
		cout << "Deseja inserir mais números? (1 para 'sim' e 0 para 'não')" << endl;
		cin >> decisao;
		if(!(decisao == 0) & !(decisao == 1)){
			cout << "Por favor, insira um número válido: (1 para 'sim' e 0 para 'não')" << endl;
			cin >> decisao;
		}
	}
}

void Numeros::max()	//retorna o maior número do vetor numeros
{
	int max;
	max = *max_element(lista.begin(), lista.end());
	cout << "O maior elemento da lista é: " << max << "\n";
}

void Numeros::min()	//retorna o menor número do vetor numeros
{
	int min;
	min = *min_element(lista.begin(), lista.end());
	cout << "O menor elemento da lista é: " << min << "\n";
}

void Numeros::crescente()	//retorna a lista em ordem crescente
{
	sort(lista.begin(), lista.end());
	cout << "A lista de números em ordem crescente é: ";
	for(vi=lista.begin(); vi != lista.end(); vi++){
		cout << *vi << " ";
	}
	cout << endl;
}

void Numeros::imprime()	//imprime todos os valores do vetor numeros na ordem em que foram recebidos
{
	cout << "A lista de números que você inseriu é: ";
	for(vi=lista.begin(); vi != lista.end(); vi++){
		cout << *vi << " ";
	}
	cout << endl;
}