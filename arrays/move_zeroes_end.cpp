#include <bits/stdc++.h>
using namespace std;
void moveZeroesToEnd(vector<int> &nums)
{
    int n=nums.size();
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (nums[i]!=0)
        {
            temp.push_back(nums[i]);
        }
        
       
    }

    for (int i = 0; i < temp.size(); i++)
    {
        nums[i]=temp[i];
    }

    for (int  i = temp.size()-1; i < n; i++)
    {
        nums[i]=0;
    }
    
    
}
int main()
{
    vector<int> a = {2, 1, 0, 4, 0, 0, 3, 0, 1};
    moveZeroesToEnd(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}