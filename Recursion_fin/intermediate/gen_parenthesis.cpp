#include <bits/stdc++.h>
using namespace std;

bool isValid(const string &s)
{
    int balance = 0;
    for (auto c : s)
    {
        if (c == '(')
            balance++;
        else
            balance--;
        if (balance < 0)
            return false;
    }
    return (balance == 0);
}

void solve(int n, const string &par, vector<string> &res)
{
    if (par.length() == 2 * n)
    {
        if (isValid(par))
        {
            res.push_back(par);
        }
        return;   // ← **Important**: stop further recursion here
    }
    solve(n, par + '(', res);
    solve(n, par + ')', res);
}

int main()
{
    int n = 3;
    vector<string> res;
    solve(n, "", res);  // ← start with empty string, not " "
    for (const string &s : res)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
