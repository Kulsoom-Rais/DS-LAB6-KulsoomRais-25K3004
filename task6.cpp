
#include <iostream>
using namespace std;

int maze[4][4] = {
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {0, 0, 0, 1}
};

int path[4][4] = {0};

bool solveMaze(int r, int c)
{
   
    if (r == 3 && c == 3 && maze[r][c] == 1)
    {
        path[r][c] = 1;
        return true;
    }

    
    if (r >= 4 || c >= 4 || maze[r][c] == 0)
        return false;

    
    path[r][c] = 1;

    
    if (solveMaze(r, c + 1))
        return true;

    
    if (solveMaze(r + 1, c))
        return true;

    
    path[r][c] = 0;

    return false;
}

int main()
{
    if (solveMaze(0, 0))
    {
        cout << "Valid path:\n";

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                cout << path[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "No valid path exists.";
    }

    return 0;
}

