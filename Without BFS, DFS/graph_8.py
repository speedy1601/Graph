'''
Input :
6 9
2 1           5      4     1 5 0 3           3 2     4   ---> vector of edges for every 'from'
2 5          ---    ---   ---------   ---   -----   ---
2 0           0      1        2        3      4      5   ---> index (from)
2 3
0 5
1 4
5 4
4 3
4 2

Ouput :
0 5 4
1 4 3
1 4 2
2 1 4
2 5 4
2 0 5
4 2 1            index 4 has 3, 2.. For 3 in the index 3 there is no edge. So there's no 4 3 _
4 2 5
4 2 0
4 2 3
5 4 3
5 4 2
'''
def add_directed_edge(graph:list[list[int]], fromm:int, to:int):
    graph[fromm].append(to)

def print_paths_len_2(graph:list[list[int]]):
    for i in range(len(graph)):
        for v in graph[i]:
            for w in graph[v]:
                print(f"{i} {v} {w}")
            
def main():
    nodes, edges = map(int, input().split())
    graph = [[] for _ in range(nodes)]
    for _ in range(edges):
        fromm, to = map(int, input().split())
        add_directed_edge(graph, fromm, to)
    
    print_paths_len_2(graph)

if __name__ == '__main__':
    main()