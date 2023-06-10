def add_directed_edge(graph:list, fromm:int, to:int):
    graph[fromm] = to

def show_path(graph:list, node_no:int):
    print(node_no, end = " ")
    while graph[node_no] != -1:
        print(graph[node_no], end = " ")
        node_no = graph[node_no]
    print()

def main():
    nodes, edges = map(int, input().split())
    graph = [-1] * nodes
    for _ in range(edges):
        fromm, to = map(int, input().split())
        add_directed_edge(graph, fromm, to)
    
    Q = int(input())
    for _ in range(Q):
        node_no = int(input())
        show_path(graph, node_no)
    
if __name__ == '__main__':
    main()