
#include <iostream>
using namespace std;

char grid[4][4] = {
    {'C', 'A', 'T', 'D'},
    {'B', 'D', 'T', 'A'},
    {'A', 'C', 'B', 'T'},
    {'D', 'B', 'A', 'C'}
};

bool visited[4][4] = {false};

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool searchWord(int r, int c, string word, int index)
{
    
    if (index == word.length())
        return true;

    
    if (r < 0 || r >= 4 || c < 0 || c >= 4)
        return false;

    
    if (visited[r][c] || grid[r][c] != word[index])
        return false;

    
    visited[r][c] = true;

    
    for (int i = 0; i < 4; i++)
    {
        int newRow = r + dr[i];
        int newCol = c + dc[i];

        if (searchWord(newRow, newCol, word, index + 1))
            return true;
    }

    
    visited[r][c] = false;

    return false;
}

int main()
{
    string word = "CAT";
    bool found = false;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (searchWord(i, j, word, 0))
            {
                found = true;
                break;
            }
        }

        if (found)
            break;
    }

    if (found)
        cout << "Word CAT exists in the grid.";
    else
        cout << "Word CAT does not exist in the grid.";

    return 0;
}

