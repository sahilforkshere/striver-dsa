#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    int i;
    int j;
    Node(int data, int row, int col) {
        this->data = data;
        i = row;
        j = col;
    }
};

class compare {
public:
    bool operator()(Node *a, Node *b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        int k = mat.size();
        priority_queue<Node*, vector<Node*>, compare> pq;


        for (int i = 0; i < k; i++) {
            if (!mat[i].empty()) {
                Node* tmp = new Node(mat[i][0], i, 0);
                pq.push(tmp);
            }
        }

        vector<int> ans;

    
        while (!pq.empty()) {
            Node* tmp = pq.top();
            pq.pop();

            ans.push_back(tmp->data);

            int row = tmp->i;
            int col = tmp->j;

            if (col + 1 < mat[row].size()) {
                Node* nextNode = new Node(mat[row][col + 1], row, col + 1);
                pq.push(nextNode);
            }
        }

        return ans;
    }
};
