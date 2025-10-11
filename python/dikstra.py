import heapq

def Dijkstra(g, s):
    d = [float("inf")] * len(g)
    pi = [None] * len(g)
    d[s] = 0

    def relax(u, v, w):
        if w != float("inf") and d[v] > d[u] + w:
            d[v] = d[u] + w
            pi[v] = u
            return True
        return False

    vis = [False] * len(g)
    pq = []
    heapq.heappush(pq, (0, s))

    while pq:
        cd, u = heapq.heappop(pq)
        if vis[u]:
            continue
        vis[u] = True
        for v in range(len(g)):
            weight_uv = g[u][v]
            if relax(u, v, weight_uv):
                heapq.heappush(pq, (d[v], v))

    return d, pi


def print_path(pi, v):
    path = []
    while v is not None:
        path.append(v)
        v = pi[v]
    return path[::-1] 


print("Dijkstra's algorithm")

n = int(input("Enter the number of vertices: "))

g = [[float("inf")] * n for _ in range(n)]

m = int(input("Enter the number of edges: "))
print("Enter each edge in the format: u v weight")
for _ in range(m):
    u, v, w = map(int, input().split())
    g[u][v] = w
    g[v][u] = w  

start = int(input("Enter the starting vertex: "))

dist, parent = Dijkstra(g, start)

print(f"\nShortest distances and paths from source vertex {start}:\n")
for i in range(n):
    if dist[i] == float("inf"):
        print(f"Vertex {i} : Unreachable")
    else:
        path = print_path(parent, i)
        print(f"Vertex {i} : Distance = {dist[i]}, Path = {' -> '.join(map(str, path))}")
