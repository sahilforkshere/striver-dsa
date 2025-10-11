import sys
sys.setrecursionlimit(300000)

class Node:
    __slots__ = ['child0', 'child1']
    def __init__(self):
        self.child0 = None
        self.child1 = None

def insert(root, value, depth=26):
    if depth < 0:
        return None
    new_node = Node()
    if root is not None:
        new_node.child0 = root.child0
        new_node.child1 = root.child1
    bit = (value >> depth) & 1
    if bit == 0:
        new_node.child0 = insert(root.child0 if root else None, value, depth-1)
    else:
        new_node.child1 = insert(root.child1 if root else None, value, depth-1)
    return new_node

def query(root, value):
    res = 0
    for i in range(26, -1, -1):
        bit = (value >> i) & 1
        desired = 1 - bit
        if desired == 0:
            if root and root.child0:
                res |= (1 << i)
                root = root.child0
            elif root and root.child1:
                root = root.child1
            else:
                break
        else:
            if root and root.child1:
                res |= (1 << i)
                root = root.child1
            elif root and root.child0:
                root = root.child0
            else:
                break
    return res

class Solution:
    def solve(self, A, B, C):
        # Build graph
        adj = [[] for _ in range(A+1)]
        for edge in C:
            u, v = edge[0], edge[1]
            adj[u].append(v)
            adj[v].append(u)
        
        # Precompute subtree sums and times
        subtreeSum = [0] * (A+1)
        inTime = [0] * (A+1)
        outTime = [0] * (A+1)
        timer = 0
        
        stack = [(1, 0, False)]
        while stack:
            u, p, visited = stack.pop()
            if not visited:
                inTime[u] = timer
                timer += 1
                subtreeSum[u] = B[u-1]
                stack.append((u, p, True))
                for v in adj[u]:
                    if v != p:
                        stack.append((v, u, False))
            else:
                for v in adj[u]:
                    if v != p:
                        subtreeSum[u] += subtreeSum[v]
                outTime[u] = timer - 1
        
        # Build arrays E and D
        E = []
        D = []
        for i in range(1, A+1):
            E.append((outTime[i], subtreeSum[i]))
            D.append((inTime[i], subtreeSum[i]))
        E.sort()
        D.sort()
        
        # Build persistent tries for E (prefix)
        versions_left = [None] * (A+1)
        versions_left[0] = Node()
        for i in range(A):
            versions_left[i+1] = insert(versions_left[i], E[i][1])
        
        # Build persistent tries for D (suffix)
        versions_right = [None] * (A+1)
        versions_right[A] = Node()
        for i in range(A-1, -1, -1):
            versions_right[i] = insert(versions_right[i+1], D[i][1])
        
        # Process each node i
        ans = 0
        for i in range(1, A+1):
            # Left segment: outTime < inTime[i]
            low, high = 0, A-1
            left_index = -1
            while low <= high:
                mid = (low + high) // 2
                if E[mid][0] < inTime[i]:
                    left_index = mid
                    low = mid + 1
                else:
                    high = mid - 1
            if left_index >= 0:
                candidate = query(versions_left[left_index+1], subtreeSum[i])
                ans = max(ans, candidate)
            
            # Right segment: inTime > outTime[i]
            low, high = 0, A-1
            right_index = A
            while low <= high:
                mid = (low + high) // 2
                if D[mid][0] > outTime[i]:
                    right_index = mid
                    high = mid - 1
                else:
                    low = mid + 1
            if right_index < A:
                candidate = query(versions_right[right_index], subtreeSum[i])
                ans = max(ans, candidate)
        
        return ans