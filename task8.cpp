
#include <iostream>
using namespace std;

void permute(char arr[], int index)
{
    
    if (index == 4)
    {
        for (int i = 0; i < 4; i++)
            cout << arr[i];

        cout << endl;
        return;
    }

    for (int i = index; i < 4; i++)
    {
        
        swap(arr[index], arr[i]);

        
        permute(arr, index + 1);

       
        swap(arr[index], arr[i]);
    }
}

int main()
{
    char arr[] = {'A', 'B', 'C', 'D'};

    permute(arr, 0);

    return 0;
}

