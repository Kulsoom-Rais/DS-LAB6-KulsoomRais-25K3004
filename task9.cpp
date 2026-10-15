
#include <iostream>
using namespace std;

int grid[4][4] = {
    {1, 0, 0, 4},
    {0, 4, 1, 0},
    {0, 1, 4, 0},
    {4, 0, 0, 1}
};

bool isSafe(int row, int col, int num)
{
    
    for (int i = 0; i < 4; i++)
    {
        if (grid[row][i] == num)
            return false;

        if (grid[i][col] == num)
            return false;
    }

    
    int startRow = (row / 2) * 2;
    int startCol = (col / 2) * 2;

    for (int i = startRow; i < startRow + 2; i++)
    {
        for (int j = startCol; j < startCol + 2; j++)
        {
            if (grid[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku()
{
    
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (grid[row][col] == 0)
            {
                
                for (int num = 1; num <= 4; num++)
                {
                    if (isSafe(row, col, num))
                    {
                        grid[row][col] = num;

                        if (solveSudoku())
                            return true;

                        
                        grid[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }

    
    return true;
}

int main()
{
    if (solveSudoku())
    {
        cout << "Solved Sudoku:\n";

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                cout << grid[i][j] << " ";

            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists.";
    }

    return 0;
}

