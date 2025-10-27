#include<bits/stdc++.h>
using namespace std;

void insertSorted(stack<int>& s, int a) {
    // Base case: if stack empty or top <= a, we can push a
    if ( s.empty() || s.top() <= a ) {
        s.push(a);
        return;
    }
    // Otherwise, pop top and recurse to find correct place for a
    int topVal = s.top();
    s.pop();
    insertSorted(s, a);
    s.push(topVal);
}

void sortStack(stack<int>& s) {
    // Base case: 0 or 1 elements => already sorted
    if ( s.empty() || s.size() == 1 ) {
        return;
    }
    // Pop top
    int topVal = s.top();
    s.pop();
    // Recursively sort remaining
    sortStack(s);
    // Insert topVal into sorted stack
    insertSorted(s, topVal);
}
int main()
{
    stack<int> s;
    s.push(3);
    s.push(5);
    s.push(1);
    s.push(4);
    s.push(2);
    
    sortStack(s);
        
    // Print sorted stack: largest at top
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}