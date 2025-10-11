#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& a) {
    int m = a.size();
    if (m == 0) return;
    int n = a[0].size();

    vector<bool> row(m, false);
    vector<bool> col(n, false);


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

// Second pass: set elements to zero
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (row[i] || col[j]) {
                a[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> mat = {
        {5, 0, 7, 9},
        {2, 8, 0, 1},
        {2, 3, 0, 2},
        {1, 2, 9, 0}
    };

    setZeroes(mat);

    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
