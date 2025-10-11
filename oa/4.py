import sys
sys.setrecursionlimit(10**6)

class Solution:
    def solve(self, A, B, C):
        # Build adjacency (0-indexed)
        g = [[] for _ in range(A)]
        for u, v in C:
            u -= 1; v -= 1
            g[u].append(v)
            g[v].append(u)

        W = B  # already a list of length A

        down = [0] * A
        parent = [-1] * A
        visited = [False] * A

        # 1) DFS1
        def dfs1(u, p):
            visited[u] = True
            parent[u] = p
            best = 0
            for v in g[u]:
                if v == p or visited[v]:
                    continue
                dfs1(v, u)
                best = max(best, down[v])
            down[u] = W[u] + best

        dfs1(0, -1)

        # 2) DFS2
        up = [0] * A
        ans = 0
        visited2 = [False] * A

        def dfs2(u, p):
            nonlocal ans
            visited2[u] = True

            # find top two child down-values
            top1, top2, top1_id = -1, -1, -1
            for v in g[u]:
                if v == p:
                    continue
                val = down[v]
                if val > top1:
                    top2, top1 = top1, val
                    top1_id = v
                elif val > top2:
                    top2 = val

            best_child = max(top1, 0)
            best_from_u = W[u] + max(up[u], best_child)

            ans = max(ans, best_from_u - W[u])

            # push up-values
            for v in g[u]:
                if v == p or visited2[v]:
                    continue
                use_sibling = top1 if v != top1_id else top2
                use_sibling = max(use_sibling, 0)
                up[v] = W[u] + max(up[u], use_sibling)
                dfs2(v, u)

        dfs2(0, -1)
        return ans