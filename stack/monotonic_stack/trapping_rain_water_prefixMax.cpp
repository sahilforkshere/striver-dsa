#include <iostream>
#include <vector>
using namespace std;

// Function to build prefix maximum array
vector<int> buildPrefixMax(const vector<int>& arr) {
    vector<int> prefixMaxArr(arr.size());
    prefixMaxArr[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefixMaxArr[i] = max(prefixMaxArr[i - 1], arr[i]);
    }
    return prefixMaxArr;
}

// Function to build suffix maximum array
vector<int> buildSuffixMax(const vector<int>& arr) {
    int n = arr.size();
    vector<int> suffixMaxArr(n);
    suffixMaxArr[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffixMaxArr[i] = max(suffixMaxArr[i + 1], arr[i]);
    }
    return suffixMaxArr;
}

// Function to calculate trapped rainwater
int trapWater(const vector<int>& height) {
    if (height.size() < 3) return 0;

    // Precompute prefix and suffix max arrays
    vector<int> prefixMaxArr = buildPrefixMax(height);
    vector<int> suffixMaxArr = buildSuffixMax(height);

    int totalWater = 0;
    for (int i = 0; i < height.size(); i++) {
        // Water level at i is min(leftMax, rightMax)
        int waterLevel = min(prefixMaxArr[i], suffixMaxArr[i]);

        // Add trapped water at i
        totalWater += waterLevel - height[i];
    }
    return totalWater;
}

int main() {
    // Example input
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    // Calculate and print trapped water
    int result = trapWater(height);
    cout << "Trapped Rain Water: " << result << endl;

    return 0;
}
