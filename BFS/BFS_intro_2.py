from queue import Queue

def bfs(edges:list[list[int]], n:int) -> None:
    graph = [ set() for _ in range(n) ]
    for (u,v) in edges:
        graph[u].add(v)
        graph[v].add(u)

    q = Queue()
    visited = [False] * n
    level = [0] * n
    q.put(0)
    visited[0] = True

    while not q.empty():
        for _ in range(q.qsize()):
            cur_node = q.get()
            print(cur_node, end=" ")
            for v in graph[cur_node]:
                if not visited[v]:
                    q.put(v)
                    visited[v] = True
                    level[v] = level[cur_node] + 1
                
    print()
    print('\n'.join( f'{i}  :  {v}' for i,v in enumerate(level)))

def main():
    edges = [[0,1],[0,2],[0,9],[1,5],[1,6],[2,4],[4,7],[6,8],[7,3]]
    bfs(edges, 10)

if __name__ == "__main__":
    main()