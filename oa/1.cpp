#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll rootItMaxDifference(int A, const vector<int>& B_in, const vector<vector<int>>& C) {
    int n = A;
    vector<ll> W(n);
    for (int i = 0; i < n; ++i) W[i] = (ll)B_in[i];

    // Build adjacency (0-indexed)
    vector<vector<int>> g(n);
    for (const auto& e : C) {
        int u = e[0] - 1, v = e[1] - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Root the tree at 0; build parent and an order (parent before children)
    vector<int> parent(n, -1);
    vector<int> order; order.reserve(n);
    parent[0] = -2;
    order.push_back(0);
    for (size_t i = 0; i < order.size(); ++i) {
        int u = order[i];
        for (int v : g[u]) if (parent[v] == -1) {
            parent[v] = u;
            order.push_back(v);
        }
    }
    parent[0] = -1;

    // Build children lists
    vector<vector<int>> children(n);
    for (int v = 0; v < n; ++v) {
        if (parent[v] != -1) children[parent[v]].push_back(v);
    }

    // Post-order compute down[u] = max path sum starting at u going into its subtree (or stop at u)
    vector<ll> down(n, 0);
    for (int i = (int)order.size() - 1; i >= 0; --i) {
        int u = order[i];
        ll best = W[u]; // stop at u
        for (int v : children[u]) best = max(best, W[u] + down[v]);
        down[u] = best;
    }

    // For rerooting: for each node, top1 & top2 children by down[v]
    const ll NEG = LLONG_MIN / 4;
    vector<ll> top1Val(n, NEG), top2Val(n, NEG);
    vector<int> top1Child(n, -1);
    for (int u = 0; u < n; ++u) {
        for (int v : children[u]) {
            ll val = down[v];
            if (val > top1Val[u]) {
                top2Val[u] = top1Val[u];
                top1Val[u] = val;
                top1Child[u] = v;
            } else if (val > top2Val[u]) {
                top2Val[u] = val;
            }
        }
    }

    // Pre-order compute up[u] = best path sum starting at u going first towards parent side
    vector<ll> up(n, 0);
    up[0] = W[0]; // at root, parent side doesn't exist → only stop at root counts

    // We will also track the final bestStart[u] and the answer on the fly
    ll ans = 0;

    for (int u : order) {
        // bestStart at u
        ll bestStart_u = max(down[u], up[u]);
        ans = max(ans, bestStart_u - W[u]);

        // propagate to children
        for (int v : children[u]) {
            // Best continuation from u excluding child v:
            ll best = W[u];           // stop at u
            best = max(best, up[u]);  // go further up via parent of u

            // go into a sibling of v
            if (top1Child[u] != -1) {
                if (top1Child[u] == v) {
                    if (top2Val[u] != NEG) best = max(best, W[u] + top2Val[u]);
                } else {
                    best = max(best, W[u] + top1Val[u]);
                }
            }
            // up[v] = take v then continue with 'best' from u
            up[v] = W[v] + best;
        }
    }

    return ans;
}

// -------- Optional main (reads: n, n weights, then n-1 edges) --------
// Remove main() if your judge expects only the function.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A;
    if (!(cin >> A)) return 0;
    vector<int> B(A);
    for (int i = 0; i < A; ++i) cin >> B[i];
    vector<vector<int>> C;
    C.reserve(A - 1);
    for (int i = 0; i < A - 1; ++i) {
        int u, v; cin >> u >> v;
        C.push_back({u, v});
    }
    cout << rootItMaxDifference(A, B, C) << "\n";
    return 0;
}





