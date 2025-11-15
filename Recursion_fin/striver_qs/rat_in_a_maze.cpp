class Solution {
  public:
   void  helper(int row,int col,string ds, vector<string>& res,vector<vector<int>>& maze){
        if(row==maze.size()-1 && col==maze.size()-1) {
           res.push_back(ds);
           return ;
        }
      if (row < 0 || col < 0 || row >= maze.size()|| col >= maze.size() || maze[row][col] == 0 || maze[row][col] == 2) {
        return;
    }
        int nextcol=col+1;
        int nextRow=row+1;
        int prevRow=row-1;
        int prevCol=col-1;
        
        maze[row][col]=-1;
       ds.push_back('D');
    helper(row + 1, col, ds, res, maze);
    ds.pop_back(); 

        ds.push_back('L');
    helper(row, col - 1, ds, res, maze);
    ds.pop_back(); 

    
    ds.push_back('R');
    helper(row, col + 1, ds, res, maze);
    ds.pop_back(); 

    
    ds.push_back('U');
    helper(row - 1, col, ds, res, maze);
    ds.pop_back();
    maze[row][col] = 1;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
       vector<string> res;
       string ds="";
       helper(0,0,ds,res,maze);
       return res;
       
    }
};#include <vector>
#include <string>
#include <algorithm> // For sort, if required, but not needed here

using namespace std;

// Corrected helper function
void helper(int row, int col, string ds, vector<string>& res, vector<vector<int>>& maze, int N) {
    // 1. **Base Case (Target Reached)**
    if (row == N - 1 && col == N - 1) {
        // Only proceed if the end is accessible (not 0)
        // Since we check for 0 before any move, this is often redundant, but good practice.
        if (maze[row][col] == 1) {
            res.push_back(ds);
        }
        return;
    }

    // Check for valid move: boundary, wall, or already visited
    if (row < 0 || col < 0 || row >= N || col >= N || maze[row][col] == 0 || maze[row][col] == 2) {
        return;
    }

    // 2. **Mark as Visited**
    maze[row][col] = 2; // Mark current cell as visited

    // 3. **Explore all 4 Directions (Down, Left, Right, Up)**
    
    // DOWN (D)
    ds.push_back('D');
    helper(row + 1, col, ds, res, maze, N);
    ds.pop_back(); // Backtrack: Remove 'D' from current path

    // LEFT (L)
    ds.push_back('L');
    helper(row, col - 1, ds, res, maze, N);
    ds.pop_back(); // Backtrack: Remove 'L' from current path

    // RIGHT (R)
    ds.push_back('R');
    helper(row, col + 1, ds, res, maze, N);
    ds.pop_back(); // Backtrack: Remove 'R' from current path

    // UP (U)
    ds.push_back('U');
    helper(row - 1, col, ds, res, maze, N);
    ds.pop_back(); // Backtrack: Remove 'U' from current path

    // 4. **Unmark/Reset Visited Status (Crucial for Backtracking)**
    // Restore the cell's original value (assuming 1 for open path)
    maze[row][col] = 1; 
}

// Main function
vector<string> ratInMaze(vector<vector<int>>& maze) {
    vector<string> res;
    // Check for empty maze or if the start/end is blocked
    if (maze.empty() || maze[0][0] == 0) {
        return res;
    }

    int N = maze.size();
    string ds = ""; // Path string (ds is often short for 'data structure' or 'decision string')
    helper(0, 0, ds, res, maze, N);

    // If the problem requires paths to be sorted lexicographically:
    // sort(res.begin(), res.end()); 
    
    return res;
}