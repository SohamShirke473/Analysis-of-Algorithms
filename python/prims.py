import heapq
def Prims(g, s):
    key = [float("inf")] * len(g)
    pi = [None] * len(g)
    key[s] = 0
    
    vis = [False] * len(g)
    pq = []
    heapq.heappush(pq, (0, s))
    
    while pq:
        cd, u = heapq.heappop(pq)
        if vis[u]: 
            continue
        vis[u] = True
        for v in range(len(g[u])):
            if vis[v]==False and g[u][v]<key[v]:
                pi[v]=u
                key[v]=g[u][v]
                heapq.heappush(pq, (key[v], v))
    
    return key, pi



print("Prim's algorithm implementation in Python")
n = int(input("Enter the number of vertices: "))


g = [[float("inf")] * n for _ in range(n)]

m = int(input("Enter the number of edges: "))
print("Enter each edge in the format: u v weight")
for _ in range(m):
    u, v, w = map(int, input().split())
    g[u][v] = w
    g[v][u] = w 

start = int(input("Enter the starting vertex: "))

dist, parent = Prims(g, start)

print("\nEdges in the Minimum Spanning Tree:")
total_cost = 0
for v in range(n):
    if parent[v] is not None:
        print(f"{parent[v]} -- {v}  weight = {dist[v]}")
        total_cost += dist[v]

print(f"\nTotal cost of MST: {total_cost}")


