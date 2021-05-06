#include "Sudoku.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Sudoku s;
    s.printSudoku();
    s.iniciaSudoku();
    s.resolveSudoku();
    return 0;
}
