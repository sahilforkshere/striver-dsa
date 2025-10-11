#include <bits/stdc++.h>
using namespace std;
long long result(long long n, long long k)
{
    long long temp = n;
    while (k > 0)
    {
        if (temp % 10 != 0)
        {
            temp = temp - 1;
            k--;
        }

        else
        {
            temp = temp / 10;
            k--;
        }
    }
    return temp;
}
int main()
{
    long long n;
    cout << "Enter the number\n";
    cin >> n;
    long long k;
    cout << "How many time you want to subtract\n";
    cin >> k;

    long long ans = result(n, k);
    cout << ans;

    return 0;
}