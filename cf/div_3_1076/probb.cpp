#include <bits/stdc++.h>
using namespace std;



void reversePart(vector<int>& arr, int l, int r) {
    while (l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}



void solve(){
    int n;
    cin>>n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<int> p2=p;

    int l=0;
    int r=p2.size()-1;

    while (l<r)
    {
        p2=p;
        reversePart(p2,l,r);
        if(p2>p){
            break;
        }
        l++;
        
    }

    for (int i = 0; i < p2.size(); i++)
    {
        cout<<p2[i]<<" ";
    }
    cout<<"\n";
    
    
    




}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();   
    }

    return 0;
}