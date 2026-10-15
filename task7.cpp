
#include <iostream>
using namespace std;

int arr[5] = {2, 3, 5, 6, 8};

bool findSubset(int index, int sum)
{
    
    if (sum == 9)
        return true;

    
    if (index == 5 || sum > 9)
        return false;

    
    if (findSubset(index + 1, sum + arr[index]))
    {
        cout << arr[index] << " ";
        return true;
    }

    
    if (findSubset(index + 1, sum))
        return true;

    return false;
}

int main()
{
    cout << "Subset with sum 9: ";

    if (!findSubset(0, 0))
        cout << "No valid subset exists.";

    return 0;
}

