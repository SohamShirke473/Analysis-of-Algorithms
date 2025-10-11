INF = float('inf')

def floyd_warshall(graph):
    n = len(graph)
    dist = [[graph[i][j] for j in range(n)] for i in range(n)]
    pred = [[None if graph[i][j] == INF else i for j in range(n)] for i in range(n)]

    print("\nD(0) (Initial distance matrix):")
    for row in dist:
        print(row)
    print("\nP(0) (Initial predecessor matrix):")
    for row in pred:
        print(row)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    pred[i][j] = pred[k][j]

        print(f"\nD({k+1}) (After considering vertex {k}):")
        for row in dist:
            print(row)
        print(f"\nP({k+1}) (After considering vertex {k}):")
        for row in pred:
            print(row)

    return dist, pred


def construct_path(u, v, pred):
    if pred[u][v] is None:
        return []
    path = [v]
    while v != u:
        v = pred[u][v]
        path.insert(0, v)
    return path


n = int(input("Enter number of vertices: "))
graph = []
print(f"Enter the adjacency matrix ({n}x{n}), use 'INF' for no direct edge:")

for i in range(n):
    row_input = input(f"Row {i}: ").split()
    row = [INF if val.upper() == 'INF' else float(val) for val in row_input]
    graph.append(row)

dist, pred = floyd_warshall(graph)

print("\nAll shortest paths between every pair of vertices:")
for i in range(n):
    for j in range(n):
        path = construct_path(i, j, pred)
        if path:
            print(f"{i} -> {j}: Path: {' -> '.join(map(str, path))}, Distance: {dist[i][j]}")
        else:
            print(f"{i} -> {j}: No path exists")
