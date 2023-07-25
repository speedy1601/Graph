from queue import Queue
'''
def bfs(graph:list[set[int]], n:int) -> bool:              # 2nd way
    q = Queue()
    visited = [False] * n
    q.put(0)
    visited[0] = True

    while not q.empty():
        for _ in range(q.qsize()):
            cur_node = q.get()
            for v in graph[cur_node]:
                if v > cur_node:
                    if visited[v]:
                        return False
                    q.put(v)
                    visited[v] = True
    
    return True
'''
def bfs(graph:list[set[int]], n:int) -> bool:
    q = Queue()
    visited = [False] * n
    q.put(0)
    visited[0] = True

    while not q.empty():
        cur_node = q.get()
        for v in graph[cur_node]:
            if v > cur_node:
                if visited[v]:
                    return False
                q.put(v)
                visited[v] = True

    return True

def validTree(n:int, edges:list[list[int]]):
    graph = [ set() for _ in range(n) ]
    for (u,v) in edges:
        graph[u].add(v)
        graph[v].add(u)

    return bfs(graph, n)

def main():
    edges = [[0,1],[0,2],[0,9],[1,5],[1,6],[2,4],[4,7], [8,5], [6,8],[7,3]]
    n = 10
    print( 'Valid Tree' if validTree(n, edges) else 'Non-Valid Tree' )

if __name__ == "__main__":
    main()