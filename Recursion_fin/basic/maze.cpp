#include <bits/stdc++.h>
using namespace std;
int TotalWays(int n, int m)
{
    int rightWays = 0;
    int downWays = 0;
    if (n == 1 && m == 1)
        return 1;
    if (n == 1) // down nhi ja skte
    {
        rightWays += TotalWays(n, m - 1);
    }
    else if (m == 1) // or right nhi ja skte
    {
        downWays += TotalWays(n - 1, m);
    }
    else if (n  >1 && m > 1)
    {
        rightWays += TotalWays(n, m - 1);
        downWays += TotalWays(n - 1, m);
    }

    int totalWays = rightWays + downWays;
    return totalWays;
}

int main()
{
    int n, m;
    cout << "Enter no. of rows " << " ";
    cin >> n;
    cout << "Enter no. of columns" << " ";
    cin >> m;
    int ans= TotalWays(n,m);
    cout<<ans;
    return 0;
}