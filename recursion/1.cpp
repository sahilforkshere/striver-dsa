#include <iostream>
using namespace std;

void printName(int i, int n)
{
    if (i < 1)
    {
        return;
    }

    cout << i;
    printName(i - 1, n);
}

int main()
{
    int n;
    cout << "Enter how many time you want to print ";
    cin >> n;

    printName(n, n);

    return 0;
}