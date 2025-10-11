#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        int nxt[26];
        string word; // non-empty only at terminal nodes
        Node() { fill(begin(nxt), end(nxt), -1); }
    };

    vector<Node> trie;
    int R, C;
    vector<vector<char>> *B;
    vector<string> found;

    void insert(const string &s) {
        int u = 0;
        for (char ch : s) {
            int t = ch - 'a';
            if (trie[u].nxt[t] == -1) {
                trie[u].nxt[t] = (int)trie.size();
                trie.emplace_back();
            }
            u = trie[u].nxt[t];
        }
        trie[u].word = s; // Store the word at terminal node
    }

    void dfs(int x, int y, int u) {
        char ch = (*B)[x][y];
        int t = ch - 'a';
        int v = trie[u].nxt[t];
        if (v == -1) return;

        // If we found a word, add it to results
        if (!trie[v].word.empty()) {
            found.push_back(trie[v].word);
            trie[v].word.clear(); // Mark as found to avoid duplicates
        }

        (*B)[x][y] = '#'; // mark visited
        
        // 8-direction movement
        static const int dx[8] = {-1,-1,-1,0,0,1,1,1};
        static const int dy[8] = {-1,0,1,-1,1,-1,0,1};
        
        for (int k = 0; k < 8; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
                char nextChar = (*B)[nx][ny];
                if (nextChar != '#' && trie[v].nxt[nextChar - 'a'] != -1) {
                    dfs(nx, ny, v);
                }
            }
        }
        
        (*B)[x][y] = ch; // restore
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &dictionary) {
        R = board.size();
        C = (R > 0) ? board[0].size() : 0;
        B = &board;
        found.clear();

        // Build trie
        trie.clear();
        trie.emplace_back();
        
        for (const string &w : dictionary) {
            if (w.empty()) continue;
            insert(w);
        }

        // Search for words in board
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                char ch = board[i][j];
                if (ch >= 'a' && ch <= 'z' && trie[0].nxt[ch - 'a'] != -1) {
                    dfs(i, j, 0);
                }
            }
        }

        // Remove duplicates and sort
        sort(found.begin(), found.end());
        found.erase(unique(found.begin(), found.end()), found.end());
        
        return found;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> board(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> board[i][j];
        }
    }

    int num_words;
    cin >> num_words;
    vector<string> dictionary(num_words);
    for (int i = 0; i < num_words; i++) {
        cin >> dictionary[i];
    }

    Solution solver;
    vector<string> found = solver.findWords(board, dictionary);

    cout << found.size() << "\n";
    for (auto &w : found) {
        cout << w << "\n";
    }
    
    return 0;
}

word puzzle