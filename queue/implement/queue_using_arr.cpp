#include<bits/stdc++.h>
using namespace std;
#define SIZE 4

int q[SIZE];
int frontIdx=0;
int rearIdx= 0;

void push(int x) {
    if (rearIdx == SIZE) {
        cout << "QUEUE IS FULL\n";
        return;
    }
    q[rearIdx++] = x;

}

int pop() {
    if (frontIdx == rearIdx) {
        cout << "Queue is Empty\n";
        return -1;    // return some sentinel value; or throw
    }
    return q[frontIdx++];
}
int main()
{

 return 0;
}