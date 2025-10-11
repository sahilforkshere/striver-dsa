#include <bits/stdc++.h>
using namespace std;

//brute force
void rotateByK(vector<int> &a, int n, int k)
{
    k=k%n;
    vector<int> temp;
    for (int i = 0; i < k; i++)
    {
        temp.push_back(a[i]);
    }

    for (int j = k; j < a.size(); j++)
    {
        a[j - k] = a[j];
    }

    for (int i = 0; i < k; i++) {
        a[n - k + i] = temp[i];
    }
}

//most optimal 

void rotateByKopt(int *a,int n,int k){
    
    reverse(a,a+k);
    reverse(a+k,a+n);
    reverse(a,a+n);


   

}

int main()
{
    int a[] = {3, 1, 5, 4, 6};
    int k;
    cout << "How many place you want rotate \n";
    cin >> k;

    rotateByKopt(a, 5, k);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }


    return 0;
}