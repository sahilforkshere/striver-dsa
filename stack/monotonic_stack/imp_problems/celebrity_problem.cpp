

#include <bits/stdc++.h>
using namespace std;

        int celebrity_problem( vector<vector<int>> mat)
        {
            int n = mat.size();
            int m = mat[0].size();

            vector<int> knowMe(n,0);
            vector <int> Iknow(n,0);

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (mat[i][j] == 1)
                    {
                        knowMe[j]++;
                        Iknow[i]++;
                    }

                }
            }

            for (int i = 0; i < n; i++)
            {
                if (knowMe[i]==n-1 && Iknow[i]==0)
                {
                    return i;
                }

            }
            return -1;
        }


int main()
{
            vector<vector<int>> mat={

                {0,1,1,0},
                {0,0,1,0},
                {0,0,0,0},
                {1,1,1,0}
            };
            int ans=celebrity_problem(mat);
            cout<<ans<<endl;
    return 0;
}
