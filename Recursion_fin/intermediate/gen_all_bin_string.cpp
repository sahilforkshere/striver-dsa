#include <bits/stdc++.h>
using namespace std;

void BinStrings(int n, string s, vector<string> &res) {
    if (s.length() == n) {
        res.push_back(s);
        return;
    }
    // Append 0
    BinStrings(n, s + '0', res);

    // Append 1 only if last character is not '1'
    if (s.empty() || s.back() != '1') {
        BinStrings(n, s + '1', res);
    }
}

int main(){
    int n;
    cout << "Enter a no.: ";
    cin >> n;

    vector<string> res;
    BinStrings(n, "", res);

    for (const string &s : res) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
