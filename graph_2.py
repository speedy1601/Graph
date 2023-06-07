''' 
Problem #2: Adjacency Hashset Representation             USING   defaultdict(set) 
● Can we iterate on neighbours efficiently (O(Degree )), while still checking whether an edge exists or not in O(1)?
  The best of 2 worlds? 
● Simply, yes. Instead of a list per node, use a hashset! 
● typedef vector<unordered_set<int>> GRAPH; 
   ○ Assume it is unweighted graph 
- Implement : void add_directed_edge(...), void add_undirected_edge, void print(...)
'''
from collections import defaultdict

def add_directed_edge(graph:list, fromm:int, to:int) :
    graph[fromm].add(to)

def add_undirected_edge(graph:list, fromm:int, to:int) :
    graph[fromm].add(to)
    graph[to].add(fromm)

def print_adjacency_list(graph:list) :
    for node, neighbours in graph.items() :
        print(f"Node {node} has {len(neighbours)} neighbours : {', '.join(map(str, neighbours))}")

def Main() :
    graph = defaultdict(set)
    edges = int(input()) # since it's a dict, we don't need nodes to define the maximum node in our dict. For list
                         # it's needed to access any index. 
    for _ in range(edges):
        fromm, to = map(int, input().split())
        add_directed_edge(graph, fromm, to)
    
    print_adjacency_list(graph)

if __name__ == '__main__' :
    Main()

'''
Output :
5
0 1
2 5
3 8
1 4
2 7
Node 0 has 1 neighbours : 1
Node 2 has 2 neighbours : 5, 7
Node 3 has 1 neighbours : 8
Node 1 has 1 neighbours : 4
'''