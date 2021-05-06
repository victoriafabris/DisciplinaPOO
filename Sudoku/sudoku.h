#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sudoku
{
public:
    void iniciaSudoku();	//usuário monta o grid do Sudoku
    void printSudoku();		//printa Sudoku
    void resolveSudoku();	//usuário resolve o Sudoku
    bool fimdoSudoku();		//verifica se Sudoku chegou ao fim
    bool solucaoSudoku();	//máquina resolve o sudoku e armazena resultado
    bool gridVazio(int linha, int col);			//procura por grids vazios
    bool checagem(int linha, int col, int num);	//checa se há número na linha ou coluna
    bool temnaLinha(int linha, int num);		//checa se há número na linha
    bool temnaCol(int col, int num);			//checa se há número na coluna
    bool temnoBox(int linhaBox, int colBox, int num);	//checa se há número no box
    bool gridCorreto(int grid[9][9], int i, int j, int num);
    vector<vector<vector<int> > > grid1 = vector<vector<vector<int>>>(9, vector<vector<int>>(9, vector<int>(0))); //grid de soluções
    vector<vector<int> > grid2 = vector<vector<int>>(9, vector<int>(9, 0)); //grid finalizado!
    int s;
    int i;
};

#endif /* SUDOKU_H_ */
