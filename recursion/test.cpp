#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    cout << "Enter a number: ";
    cin >> a;
    int n = stoi(a);
    ++n;
    string b = to_string(n);
    cout << b;
    return 0;
}
