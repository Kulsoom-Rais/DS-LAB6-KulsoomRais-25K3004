#include <iostream>
using namespace std;

const int V = 4;
const int COLORS = 3;

int graph[V][V] = {
    {0, 1, 1, 0},  
    {1, 0, 1, 1},  
    {1, 1, 0, 1},  
    {0, 1, 1, 0}   
};

string color[COLORS] = {"Red", "Green", "Blue"};
int result[V];

bool isSafe(int v, int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] == 1 && result[i] == c)
            return false;
    }

    return true;
}

bool graphColoring(int v)
{
    if (v == V)
        return true;

    for (int c = 0; c < COLORS; c++)
    {
        if (isSafe(v, c))
        {
            result[v] = c;

            if (graphColoring(v + 1))
                return true;

            result[v] = -1;  // Backtrack
        }
    }

    return false;
}

int main()
{
    for (int i = 0; i < V; i++)
        result[i] = -1;

    if (graphColoring(0))
    {
        cout << "Valid coloring exists:\n";

        for (int i = 0; i < V; i++)
            cout << char('A' + i) << " = "
                 << color[result[i]] << endl;
    }
    else
    {
        cout << "No valid coloring exists.";
    }

    return 0;
}
