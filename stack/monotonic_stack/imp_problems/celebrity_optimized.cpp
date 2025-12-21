#include <bits/stdc++.h>
using namespace std;
int celebrityProblem(vector<vector<int>> mat)
{
    int n=mat.size();

    int top=0;
    int bottom =n-1;
    while (bottom>top)
    {
        if (mat[top][bottom]==0 && )
        {
            bottom--;
        }
        else if (mat[bottom][top]==0 )
        {
            top++;
        }
        else
        {
            top++;
            bottom--;
        }








    }

    if (top> bottom)
    {
        return -1;
    }
    for (int i=0;i<n;i++)
    {
        if (i==top)
        {
            continue;
        }
        if (mat[i][top]==0 && mat[i][top]==1)
        {
            continue;
        }



            else
            {
                return -1;
            }


    }

    return top;



}
int main()
{
    vector<vector<int>> mat={

        {0,1,1,0},
        {0,0,1,0},
        {0,0,0,0},
        {1,1,1,0}
    };
    int ans=celebrityProblem(mat);
    cout<<ans<<endl;
    return 0;
}

