void helper(vector<string>& res, string& ds, int n, int ind, vector<string>& a) {
    
    // Base Case 1: (Success)
    // We found a combination of the target size 'n'.
    if (ds.size() == n) {
        res.push_back(ds);
        return;
    }

    // Base Case 2: (Failure/Stop)
    // We've run out of elements (ind is past the end of 'a').
    if (ind == a.size()) {
        return;
    }

    // --- Recursive Call 1: "PICK" the element at a[ind] ---
    // (This is the block you wrote)
    
    // 1. Choose: Add the current element
    ds.push_back(a[ind]);
    
    // 2. Explore: Recurse, moving to the next element (ind + 1)
    helper(res, ds, n, ind + 1, a);
    
    // 3. Unchoose (Backtrack): Remove the element
    ds.pop_back();

    
    // --- Recursive Call 2: "DON'T PICK" the element at a[ind] ---
    // (This was the missing part)
    
    // 1. Explore: Recurse, moving to the next element (ind + 1)
    //    *without* adding a[ind] to the string.
    helper(res, ds, n, ind + 1, a);
}