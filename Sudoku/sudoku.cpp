#include "Sudoku.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//montagem do Sudoku pelo usuário
//números aqui colocados serão fixos, então ficarão armazenados no grid finalizado (grid2)
//após a montagem, usuário tentará resolver o sudoku
void Sudoku::iniciaSudoku()
{
	int linha, coluna, numero;
	char decisao = 's';
	//loop
	while (decisao == 's') {
		solucaoSudoku();
		cout << "De o numero da linha (numero entre 1-9): \n";
		cin >> linha;
		cout << "De o numero da coluna (numero entre 1-9): \n";
		cin >> coluna;
		cout << "De o numero para ficar dentro do grid correspondente (numero entre 1-9): \n";
		cin >> numero;
		vector<int> vetor = grid1[linha-1][coluna-1];
		if(find(vetor.begin(), vetor.end(), numero) == vetor.end()){
			//se n existe no vetor, valor está correto
			cout << "Este numero já esta presente no Sudoku, insira outro. \n";
			continue;
		}
		grid2[linha-1][coluna-1] = numero; //grid finalizado, numero fica fixo
		printSudoku();
		while(true){
			cout << "Deseja inserir mais numeros? Digite s para sim e n para nao.\n";
			cin >> decisao;
			if (decisao != 'n' && decisao != 's')
			{
				cout << "Por favor, digite s ou n somente.\n";
				continue;
			}
			break;
		}
	}
	solucaoSudoku();
}

//usuário resolve o Sudoku
//números aqui que correspondem aos números já calculados pelo algoritmo serão fixados, ficarão armazenados no grid finalizado (grid2)
void Sudoku::resolveSudoku(){
	int linha, coluna, numero;
	cout << "Comece a solucionar o Sudoku:\n";
	while(true){
		cout << "De o numero da linha (numero entre 1-9): \n";
		cin >> linha;
		cout << "De o numero da coluna (numero entre 1-9): \n";
		cin >> coluna;
		cout << "De o numero para ficar dentro do grid correspondente (numero entre 1-9): \n";
		cin >> numero;
		//procura por [linha][coluna]=numero em grid1
		vector<int> vetor = grid1[linha-1][coluna-1];
		if(find(vetor.begin(), vetor.end(), numero) != vetor.end()){ //se retorna vetor.end, numero não existe em grid1
			//se for diferente, armazena no grid2, numero é solucao
			grid2[linha-1][coluna-1] = numero;
			solucaoSudoku();
			printSudoku();
			//verificar se chegou no fim
			if(fimdoSudoku()){ //se true: terminou, se false: não terminou
				cout
						<< "Sudoku finalizado, parabens!!! \n";
				printSudoku();
				break;
			}
		} else{
			cout << "Este numero já esta presente no Sudoku, insira outro. \n"; //volta pra linha 51
		}
	}
}

bool Sudoku::fimdoSudoku()
{
	int linha, coluna;
	//loop para checar se todos os espacos foram preenchidos
	for (linha = 0; linha < 9; linha++) { //checa todas as linhas, de 0 a 9
		for (coluna = 0; coluna < 9; coluna++) { //checa todas as colunas, de 0 a 9
			if (gridVazio(linha, coluna)) {	//se for verdade (se tiver espaços vazios) continua recebendo numeros do usuario
				return false; //não acabou
			}
		}
	}
	//término do jogo
	return true;
}

void Sudoku::printSudoku() //exibe Sudoku na tela
{
	cout << "\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << grid2[i][j] << " ";
			if ((j == 2) || (j == 5)) {
				cout << " | ";
			}
		}
		if ((i == 2) || (i == 5)) {
			cout << endl;
			for (int k = 0; k < 9; k++)
				cout << "---";
		}
		cout << "\n";
	}
}

//método que calcula possíveis soluções e as armazena em grid1 - grid de soluções
bool Sudoku::solucaoSudoku()
{
	for (int linha = 0; linha < 9; linha++)
	{
		for (int coluna = 0; coluna < 9; coluna++)
		{
			if (gridVazio(linha, coluna)) //procura por um espaço vazio no grid2
			{
				//checa grid1 e calcula possíveis soluções
				grid1[linha][coluna].clear(); //limpando todas as possibilidades anteriores
				for (int num = 1; num <= 9; num++) { //checa quais numeros cabem em cada grid para o Sudoku montado pelo usuário
					if (checagem(linha, coluna, num)) //se num não estiver em linha, coluna ou box, então atribui num ao grid1
					{
						grid1[linha][coluna].push_back(num); //atribuindo
					}
				}
				if (grid1[linha][coluna].empty()) //se o vetor for vazio, quer dizer que não há solução para o Sudoku montado pelo usuário
				{
					return false;
				}
			}
		}
	}
	return true; //há solução!
}

//encontra grids zerados no Sudoku grid2 (finalizado)
bool Sudoku::gridVazio(int linha, int col) //como parâmetro possui os endereços das linhas e colunas
{
	for (linha = 0; linha < 9; linha++) {
		for (col = 0; col < 9; col++) {
			if (grid2[linha][col] == 0)
				return true;
		}
	}
	return false;
}

bool Sudoku::checagem(int linha, int col, int num) {
	if (!temnaLinha(linha, num))	//verifica se num já está na linha
	{
		if (!temnaCol(col, num))	//verifica se num já está na coluna
		{
			int linhaBox = linha - linha % 3;//calcula numero da linha que precisa checar no box
			int colBox = col - col % 3;	//calcula numero da coluna que precisa checar no box
			if (!temnoBox(linhaBox, colBox, num))//verifica se num já está no box 3x3
			{
				return true; //se num não estiver nem na linha, nem na coluna e nem no box, então retorna verdadeiro
			}
		}
	}
	return false;//se num já está presente ou na linha, ou na coluna ou no box, retorna falso
}

bool Sudoku::temnaLinha(int linha, int num) {
	for (int i = 0; i < 9; i++) {
		if (num != 0 && grid2[linha][i] == num) //se estiver, retorna verdadeiro
			return true;
	}
	return false;
}

bool Sudoku::temnaCol(int col, int num) {
	for (int i = 0; i < 9; i++) {
		if (num != 0 && grid2[i][col] == num)	//se estiver, retorna verdadeiro
				{
			return true;
		}
	}
	return false;
}

bool Sudoku::temnoBox(int linhaBox, int colBox, int num) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid2[i + linhaBox][j + colBox] == num)	//se em algum grid do box estiver o num, então retorna true
					{
				return true;
			}
		}
	}
	return false;
}

