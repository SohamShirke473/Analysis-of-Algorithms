class DS:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [1] * n

    def find(self, i):
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, x, y):
        s1 = self.find(x)
        s2 = self.find(y)
        if s1 != s2:
            if self.rank[s1] < self.rank[s2]:
                self.parent[s1] = s2
            elif self.rank[s1] > self.rank[s2]:
                self.parent[s2] = s1
            else:
                self.parent[s2] = s1
                self.rank[s1] += 1


def kruskal(G):
    A = []  
    ds = DS(len(G))
    total_weight = 0
    edges = []

    
    for u in range(len(G)):
        for v in range(u + 1, len(G)):
            edges.append([G[u][v], u, v])

    edges.sort()

    for weight, u, v in edges:
        if ds.find(u) != ds.find(v):
            ds.union(u, v)
            A.append((u, v, weight))
            total_weight += weight
    return A, total_weight


n = int(input("Enter the number of vertices: "))

g = [[float("inf")] * n for _ in range(n)]

m = int(input("Enter the number of edges: "))
print("Enter each edge in the format: u v weight")
for _ in range(m):
    u, v, w = map(int, input().split())
    g[u][v] = w
    g[v][u] = w

mst, total_weight = kruskal(g)

print("\nMinimum Spanning Tree edges:")
for u, v, w in mst:
    print(f"{u} -- {v}  weight: {w}")

print(f"\nTotal weight of MST: {total_weight}")
