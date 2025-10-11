def bfs(graph, start):
    visited = [False] * len(graph)
    queue = []
    labels = ["A", "B", "C", "D","E"] 
    
    visited[start] = True
    queue.append(start)
    
    while queue:
        
        vertex = queue.pop(0)
        print(labels[vertex], end=" ")
        
      
        for i in range(len(graph[vertex])):
            if graph[vertex][i] == 1 and not visited[i]:
                visited[i] = True
                queue.append(i)

def dfs(graph, start):
    visited = [False] * len(graph)
    stack = [start]
    labels = ["A", "B", "C", "D","E"]   

    while stack:
        node = stack.pop()  
        if not visited[node]:
            visited[node] = True
            print(labels[node], end=" ")

            
            for i in range(len(graph[node]) - 1, -1, -1):
                if graph[node][i] == 1 and not visited[i]:
                    stack.append(i)


n=int(input("Enter the number of vertices: "))
graph = [[0]*n for _ in range(n)]
e=int(input("Enter the number of edges: "))
print("Enter edges in the format: u v")
for i in range(e):
    u,v=map(int,input().split())
    graph[u][v]=1
    graph[v][u]=1

start=int(input("Enter the starting vertex: "))   
print("BFS starting from vertex A:")
bfs(graph, start)
print("\nDFS starting from vertex B:")
dfs(graph, start)