#include <vector>
#include <string>

// We use the standard namespace to avoid writing std:: before vector, string, etc.
using namespace std;

class Solution {
public:
    /**
     * Checks if it's safe to place a queen at board[row][col].
     * This function only needs to check the 3 directions to the left
     * (upper-left diagonal, left horizontal, and lower-left diagonal),
     * because we are placing queens column by column from left to right.
     *
     * @param row The row we are checking.
     * @param col The column we are checking.
     * @param board The current chessboard state.
     * @param n The size of the board (n x n).
     * @return true if the spot is safe, false otherwise.
     */
    bool isSafe(int row, int col, vector<string>& board, int n) {
        
        // --- Save Original Coordinates ---
        // We store the original 'row' and 'col' because we need to
        // start from this *exact* same spot for all three of our checks.
        // The loops will change the values of 'row' and 'col',
        // so we need 'duprow' and 'dupcol' to reset them.
        int duprow = row;
        int dupcol = col;

        // --- 1. Check Upper-Left Diagonal ---
        // This loop moves up and to the left (row--, col--)
        //
        //  <- Q
        //    -
        //     -
        //      (row, col)
        //
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false; // Found a queen
            row--;
            col--;
        }

        // --- 2. Check Left Horizontal ---
        // We *must* reset 'row' and 'col' back to their original values
        // before starting the next check.
        col = dupcol;
        row = duprow;
        //
        //  <- Q --- (row, col)
        //
        while (col >= 0) {
            if (board[row][col] == 'Q') return false; // Found a queen
            col--;
        }

        // --- 3. Check Lower-Left Diagonal ---
        // Again, we *must* reset 'row' and 'col' one last time.
        row = duprow;
        col = dupcol;
        //
        //      (row, col)
        //     -
        //    -
        //  <- Q
        //
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false; // Found a queen
            row++;
            col--;
        }

        // If we checked all 3 directions and found no queens,
        // the spot is safe.
        return true;
    }

    /**
     * The main recursive backtracking function.
     *
     * @param col The current column we are trying to place a queen in.
     * @param board The n x n chessboard.
     * @param ans The vector to store all valid solutions.
     * @param n The size of the board (n x n).
     */
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        
        // --- Base Case ---
        // If we have successfully placed queens in all columns from 0 to n-1,
        // 'col' will become 'n'. This means we found a valid solution.
        if (col == n) {
            ans.push_back(board); // Add this solution to our answer list
            return; // Go back to explore other possibilities
        }

        // --- Recursive Step ---
        // Try placing a queen in every 'row' of the current 'col'
        for (int row = 0; row < n; row++) {
            
            // Check if placing a queen at (row, col) is safe
            if (isSafe(row, col, board, n)) {
                
                // --- Do (Place the Queen) ---
                // If it's safe, place the queen here.
                board[row][col] = 'Q';

                // --- Recurse ---
                // Move to the *next* column (col + 1) and try to place
                // the next queen.
                solve(col + 1, board, ans, n);

                // --- Undo (Backtrack) ---
                // When we return from the recursive call (either because we
                // found a solution or hit a dead end), we *must* remove
                // the queen we just placed.
                // This "undoes" our choice so we can try placing the queen
                // in the *next row* of this *same column* in the loop.
                board[row][col] = '.';
            }
        }
    }

    /**
     * The main function to solve the N-Queens problem.
     *
     * @param n The size of the chessboard (n x n).
     * @return A vector of vectors of strings, representing all
     * distinct solutions.
     */
    vector<vector<string>> solveNQueens(int n) {
        // This will store all valid board solutions
        vector<vector<string>> ans; 
        
        // This is our n x n chessboard
        // It's a vector of strings, where each string is a row.
        vector<string> board(n);
        
        // A helper string, e.g., "...." for n=4
        string s(n, '.'); 
        
        // --- Initialize the board ---
        // We must fill every row of our 'board' vector with the
        // empty 's' string.
        //
        // *** This is the bug fix ***
        // Your original code was (i < n-1), which meant the last
        // row (board[n-1]) was never initialized.
        // It was an empty string "", causing an out-of-bounds error.
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        // Start the recursive process from the first column (col = 0)
        solve(0, board, ans, n);
        
        return ans;
    }
};