#include <bits/stdc++.h>
using namespace std;


    string removeKdigits(string num, int k) {
        // Edge case: If we need to remove all digits
        if (k >= num.length()) {
            return "0";
        }

        stack<char> s; // Use char stack for easier string building

        for (int i = 0; i < num.length(); i++) {
            char current = num[i];

            // Monotonic Stack: Keep popping if current digit is smaller than the previous one
            // This ensures the smallest digits are at the start (most significant positions)
            while (!s.empty() && k > 0 && s.top() > current) {
                s.pop();
                k--;
            }

            // Optimization: Avoid pushing leading zeros onto an empty stack
            // Example: for "10200", after popping '1', we encounter '0'.
            // If stack is empty, don't push '0'.
            if (!s.empty() || current != '0') {
                s.push(current);
            }
        }

        // If k > 0, we still need to remove digits from the end
        // (e.g., input "12345", k=2 -> remove 4, 5)
        while (k > 0 && !s.empty()) {
            s.pop();
            k--;
        }

        if (s.empty()) {
            return "0";
        }

        // Build the result string from the stack
        string res = "";
        while (!s.empty()) {
            res += s.top();
            s.pop();
        }

        // The stack gives us the string in reverse order
        reverse(res.begin(), res.end());

        return res.empty() ? "0" : res;
    }


int main()
{
    string s;
    cin >> s;
    int k ;
    cin >> k;
        string result = removeKdigits(s, k);
    cout << result << endl;

    return 0;
}
