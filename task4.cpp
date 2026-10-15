#include <iostream>
using namespace std;

int savings(int n)
{
    if (n == 1)
        return 10;

    return 2 * savings(n - 1);
}

int main()
{
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    cout << "Amount on Day " << n << " = Rs. " << savings(n);

    return 0;
}
