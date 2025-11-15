#include <stack>
using namespace std;

class MinStack {
private:
 stack<int> s1;  // holds all values
 stack<int> s2;  // holds min-so-far values
public:
 MinStack() {
  // nothing special needed in constructor
 }

 void push(int val) {
  s1.push(val);
  if (s2.empty()) {
   s2.push(val);
  } else {
   int currentMin = s2.top();
   if (val < currentMin) {
    s2.push(val);
   } else {
    s2.push(currentMin);
   }
  }
 }

 void pop() {
  s1.pop();
  s2.pop();
 }

 int top() {
  return s1.top();
 }

 int getMin() {
  return s2.top();
 }
};
