#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int a[100];
    int size=0;
    heap(){
        a[0]=-1;
        size=0;
    }
    void insert(int val){
            size=size+1;
            int index=size;
            a[index]=val;

            while (index>1)
            {
                int par=index/2;
                if(a[par]<a[index]){
                    swap(a[par],a[index]);
                    index=par;
                }
                else{
                    return;
                }
            }
            
    }
    void deleteheap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        //put last element to first index
        a[1]=a[size];
        //diconnect last 
        size--;
        //take root to its correct pos
        int i=1;
        while(i<size){
            int li=2*i;
            int ri=2*i+1;
            if(li<size && a[i]<a[li]){
                swap(a[li],a[i]);
                i=li;
            }
            else if( ri<size && a[i]<a[ri]){
                    swap(a[i],a[ri]);
                    i=ri;
             }
             else{
                return;
             }
        }
    }
    void heapify(vector<int> a,int n ,int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;
        if(left<n && a[largest]<a[left]){
            largest=left;
        }
        if(right<n && a[largest]<a[right]){
            largest=right;
        }

        if(largest!=i){
            swap(a[largest],a[i]);
        }
        heapify(a,n,largest);
    }
    void print(){
        for (int i = 1; i <=size; i++)
        {
            cout<<a[i]<<"";
        }
        cout<<endl;
        
    }
    void heapsort(vector<int> v,int n){
        int size=n;
        while (size>1)
        {
            swap(v[size],v[1]);
            size--;

        }
        heapify(v,n,1);
        
    }
};
int main()
{
    heap h;
  vector<int> a={-1,54,55,56,60,58};
    int n=a.size();
    for (int i = n/2; i >= 1; i--) {
        heapify()
}
    
 return 0;
}