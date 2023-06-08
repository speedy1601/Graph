'''
Problem #3: Adjacency matrix with multiple edges
● What if we can’t just pick up one edge from the multiple edges? 
● Change the adjacency matrix representation somehow to be able to keep the multiple edges 
● Print the graph such that the edges of each node are printed first 
    ○ The order of the printed edges per (source) node doesn’t matter  
    ○ The graph edges are directed 
    ○ The graph weights are integer values

Output :

5 10
0 1 10
1 2 7
0 1 7
2 3 9
2 3 15
3 4 50
0 4 52
0 4 30
2 4 36
4 0 150

From 0 to 1 the cost is 10
From 0 to 1 the cost is 7 
From 0 to 4 the cost is 52
From 0 to 4 the cost is 30
From 1 to 2 the cost is 7
From 2 to 3 the cost is 9
From 2 to 3 the cost is 15
From 2 to 4 the cost is 36
From 3 to 4 the cost is 50
From 4 to 0 the cost is 150
'''

def add_directed_edge(graph:list[list[list[int]]], fromm:int, to:int, cost:int) :
    graph[fromm][to].append(cost)

def print_adjacency_matrix(graph:list[list[list[int]]]) :
    for _from in range(len(graph)) :
        for _to in range(len(graph)) :
            for weight in graph[_from][_to] :
                print(f"From {_from} to {_to} the cost is {weight}")
                           
def Main() :
    nodes, edges = map(int, input().split())
    graph = [ [[] for _ in range(nodes) ] for _ in range(nodes) ]

    for _ in range(edges):
        fromm, to, cost = map(int, input().split())
        add_directed_edge(graph, fromm, to, cost)

    print()
    print_adjacency_matrix(graph)

if __name__ == '__main__' :
    Main()