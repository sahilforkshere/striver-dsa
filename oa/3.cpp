#include <bits/stdc++.h>
using namespace std;

unordered_set<int> bfs(int s, int d, int n, const vector<vector<int>>& g) {
    unordered_set<int> inf;
    if (s > n) return inf;
    queue<pair<int,int>> q;
    q.push({s, 0});
    unordered_set<int> vis;
    vis.insert(s);
    while (!q.empty()) {
        auto [u, dep] = q.front();
        q.pop();
        inf.insert(u);
        if (dep < d) {
            for (int v : g[u]) {
                if (!vis.count(v)) {
                    vis.insert(v);
                    q.push({v, dep + 1});
                }
            }
        }
    }
    return inf;
}

tuple<vector<int>, int, int> solve(const vector<pair<int, int>>& edges,
                                   const map<int, int>& cost,
                                   const map<int, int>& val,
                                   const vector<int>& order,
                                   int B, int D) {
    int n = 0;
    for (auto& p : val) n = max(n, p.first);
    for (auto& e : edges) n = max({n, e.first, e.second});

    vector<vector<int>> g(n + 1);
    for (auto& e : edges) {
        g[e.first].push_back(e.second);
        g[e.second].push_back(e.first);
    }

    vector<int> seeds;
    int totC = 0;
    unordered_set<int> inf;
    unordered_set<int> avail(order.begin(), order.end());

    while (true) {
        int best = -1;
        long long best_gain = -1;
        long long best_cost = 1;  // for comparison
        unordered_set<int> newInf;
        
        for (int u : order) {
            if (!avail.count(u)) continue;
            int c = cost.at(u);
            if (totC + c > B) continue;
            unordered_set<int> cur = bfs(u, D, n, g);
            long long gain = 0;
            unordered_set<int> tmp;
            for (int v : cur) {
                if (!inf.count(v)) {
                    gain += val.at(v);
                    tmp.insert(v);
                }
            }

            // Compare by gain/cost (using integer-based comparison)
            long long lhs = gain * best_cost;
            long long rhs = best_gain * c;
            if (lhs > rhs) {
                best_gain = gain;
                best_cost = c;
                best = u;
                newInf = tmp;
            }
        }

        if (best != -1) {
            seeds.push_back(best);
            totC += cost.at(best);
            inf.insert(newInf.begin(), newInf.end());
            avail.erase(best);
        } else {
            break;
        }
    }

    int totV = 0;
    for (int v : inf) totV += val.at(v);
    return {seeds, totV, totC};
}
