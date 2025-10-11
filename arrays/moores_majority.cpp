// moore's voting algo for majority element

#include <bits/stdc++.h>
using namespace std;
int mooreVote(vector<int> &a)
{
    int n = a.size();
    int cnt = 0;
    int ans ;
    for (int i = 0; i < n; i++)
    {
         if (cnt == 0)
        {
            cnt=1;
            ans = a[i];
        }
        else if(a[i] == ans)
        {
            cnt++;
        }

        else
        {
            cnt--;
        }

       

     

       
        
    }
       int arrCnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == ans)
            {
                arrCnt++;
            }
        }

     if (arrCnt>n/2)
        {
            return ans;
        }

        return -1;
}

int main()
{
    vector<int> a = {2, 2, 3, 4, 5, 2, 2, 2, 1, 1, 2, 1, 1, 3, 2, 2, 2, 2, 2, 2};

    int ans = mooreVote(a);
    cout << ans;

    return 0;
}