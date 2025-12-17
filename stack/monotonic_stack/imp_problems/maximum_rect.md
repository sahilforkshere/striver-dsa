Here is the complete content for a Markdown file (`.md`). You can save this as `MaximalRectangle_Approach.md`.

---

```markdown
# Maximal Rectangle: Solution Approach

## 1. Problem Statement
**LeetCode 85:** Given a `rows x cols` binary matrix filled with `0`'s and `1`'s, find the largest rectangle containing only `1`'s and return its area.

## 2. Core Strategy: Dimensionality Reduction
The brute-force approach to checking every possible rectangle in a 2D matrix is computationally expensive ($O(N^3 \cdot M^3)$ or similar).

To optimize this, we convert the 2D problem into $N$ instances of a 1D problem: **"Largest Rectangle in Histogram"** (LeetCode 84).

### The Intuition
Imagine scanning the matrix one row at a time, from top to bottom. For each row, we can visualize the consecutive `1`s above it as "bars" in a histogram.

* If a cell is `1`, the bar height increases by extending the bar from the row above.
* If a cell is `0`, the bar "breaks," and the height resets to 0 immediately (since a rectangle cannot float over a gap).

By calculating the "Largest Rectangle in Histogram" for every row's generated heights, the maximum value found across all rows will be our answer.

---

## 3. Visualizing the Transformation

Consider the following Input Matrix:

```text
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]

```

We process this row by row to build our `psum` (heights) arrays:

### Row 0

* **Input:** `1 0 1 0 0`
* **Height:** `[1, 0, 1, 0, 0]`
* **Action:** Solve Histogram for `[1, 0, 1, 0, 0]`. Max Area = **1**.

### Row 1

* **Input:** `1 0 1 1 1`
* **Height:** `[2, 0, 2, 1, 1]` (Accumulate from Row 0)
* **Action:** Solve Histogram for `[2, 0, 2, 1, 1]`. Max Area = **3**.

### Row 2

* **Input:** `1 1 1 1 1`
* **Height:** `[3, 1, 3, 2, 2]` (Accumulate from Row 1. Note column 1 became 1 because it was 0 before).
* **Action:** Solve Histogram for `[3, 1, 3, 2, 2]`. Max Area = **6**. (The block of height 2 and width 3).

### Row 3

* **Input:** `1 0 0 1 0`
* **Height:** `[4, 0, 0, 3, 0]` (Columns 1, 2, 4 reset to 0 because current cell is '0').
* **Action:** Solve Histogram for `[4, 0, 0, 3, 0]`. Max Area = **4**.

**Global Max Area = 6.**

---

## 4. Algorithm Step-by-Step

### Step A: The Histogram Solver (Monotonic Stack)

We need a helper function (previously written) that efficiently finds the largest rectangle in a 1D array.

* **Data Structure:** Stack (stores indices).
* **Property:** Monotonic Increasing.
* **Logic:**
1. Iterate through heights.
2. If `current_height < stack_top_height`, we found a "Next Smaller Element" (NSE).
3. Pop from stack and calculate area for the popped height using:


4. Push current index.



### Step B: The Matrix Traversal (Vertical Prefix Sum)

We construct the height arrays.

1. Initialize a `psum` matrix (or a single 1D vector) with 0s.
2. Iterate through the matrix.
3. **Update Logic:**
* If `matrix[i][j] == '1'`: `psum[i][j] = psum[i-1][j] + 1` (conceptually).
* If `matrix[i][j] == '0'`: `psum[i][j] = 0`.


4. After updating a row, pass it immediately to the Histogram Solver.

---

## 5. Complexity Analysis

Let N be the number of rows and M be the number of columns.

### Time Complexity: O(N \times M)

* **Matrix Traversal:** We visit every cell to build the heights: O(N \times M).
* **Histogram Calculation:** For each row, we run the monotonic stack algorithm. The stack algorithm is linear O(M). We do this N times. Total: O(N \times M).
* **Overall:** The dominant term is O(N \times M).

### Space Complexity: O(N \times M) or O(M)

* **Current Implementation:** Uses a 2D vector `psum[N][M]`, so space is O(N \times M).
* **Optimization:** We can optimize this to O(M) because we only need the *previous row's* height to calculate the *current row's* height. We don't need to store the history of all rows.

---

## 6. Implementation Notes

* **Handling Char vs Int:** The input is usually `vector<vector<char>>`. Remember to convert `'1'` to integer `1` (or check `val == '1'`) and handle `'0'` resets correctly.
* **Stack Cleanup:** After iterating through the array in the histogram function, the stack might not be empty (if the array ends with an increasing sequence). You must process the remaining elements in the stack assuming the "Next Smaller Element" is the end of the array (n).

```cpp
// Logic snippet for reset
if (matrix[i][j] == '0') {
    heights[j] = 0;
} else {
    heights[j] += 1;
}

```

```

```