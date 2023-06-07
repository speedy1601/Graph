#                         USING  [set() for _ in range(nodes)]
def add_directed_edge(graph:list, fromm:int, to:int) :
    graph[fromm].add(to)

def add_undirected_edge(graph:list, fromm:int, to:int) :
    graph[fromm].add(to)
    graph[to].add(fromm)

def print_adjacency_list(graph:list) :
    for node, neighbours in enumerate(graph) :
        if len(neighbours) > 0 :
            print(f"Node {node} has {len(neighbours)} neighbours : {', '.join(map(str, neighbours))}")

def Main() :
    nodes, edges = map(int, input().split())
    graph = [set() for _ in range(nodes)]

    for _ in range(edges):
        fromm, to = map(int, input().split())
        add_directed_edge(graph, fromm, to)
    
    print()
    print_adjacency_list(graph)

if __name__ == '__main__' :
    Main()