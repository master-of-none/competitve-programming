from collections import deque

def find_indegree(graph):
    indegree = {node: 0 for node in graph}
    
    for node in graph:
        for neighbor in graph[node]:
            indegree[neighbor] += 1
    
    return indegree

def topological_sort(graph):
    res = []
    q = deque()
    indegree = find_indegree(graph)
    
    for node in graph:
        if indegree[node] == 0:
            q.append(node)
        
    while q:
        node = q.popleft()
        res.append(node)
            
        for neighbor in graph[node]:
            indegree[neighbor] -= 1
                
            if indegree[neighbor] == 0:
                q.append(neighbor)
    
    return res if len(graph) == len(res) else None

def main():
    graph = {
        'A': ['C'],
        'B': ['C', 'D'],
        'C': ['E'],
        'D': ['F'],
        'E': ['H', 'F'],
        'F': ['G'],
        'G': [],
        'H': []
    }

    order = topological_sort(graph)
    if order:
        print("Topological Order:", order)
    else:
        print("The graph has a cycle, so topological sort is not possible.")

if __name__ == "__main__":
    main()