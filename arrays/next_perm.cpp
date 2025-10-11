void nextPermutation(vector<int>& arr) {
    int idx = -1;
    int n = arr.size();
    
    // 1. Find breaking point
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] < arr[i + 1]) {
            idx = i;
            break;
        }
    }

    // 2. If no such point, reverse the whole array and return
    if (idx == -1) {
        reverse(arr.begin(), arr.end());
        return;  // important to exit here
    }

    // 3. Find the first element > arr[idx] from the end
    for (int i = n - 1; i > idx; --i) {
        if (arr[i] > arr[idx]) {
            swap(arr[i], arr[idx]);
            break;
        }
    }

    // 4. Reverse the tail
    reverse(arr.begin() + idx + 1, arr.end());
}
