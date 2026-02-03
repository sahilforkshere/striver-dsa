#include <bits/stdc++.h>
using namespace std;

int sumvec(vector<int> & arr){
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    return sum;
}

void solve() {
    int n, s, x;
    cin >> n >> s >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int fin=sumvec(a);
    if(fin>s){
        cout<<"NO\n";
    return;
    }


    int diff=(s-fin)%x;
    if(diff==0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    
    


        
        
    
 

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
