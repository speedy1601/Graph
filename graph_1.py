''' 
Problem #1: Edge List representation
● An edge list representation is a collection of the graph edges. 
● For example, if we have 10 edges, then we have a vector of 10 edges 
● typedef vector<edge> GRAPH; 
● Implement a class edge that contains the relevant edges information 
        ○ The edges should be comparable based on the edge weight 
● void add_edge(GRAPH &graph, int from, int to, int cost) 
● void print_adjaceny_matrix(GRAPH &graph) 
● Read the edges into the data structure. Print them ordered based on cost 
'''
class edge :

    def __init__(self, _fromm:int, _to:int, _weight:int) :
        self.fromm = _fromm
        self.to = _to
        self.weight = _weight
    
    def __lt__(self, other) :
        return self.weight < other.weight
    
    def print(self) :
        print(f"Edge ({self.fromm} {self.to} {self.weight})")
       
def add_edge(graph:list, fromm:int, to:int, cost:int) :
    graph.append(edge(fromm, to, cost))

def print_adjacency_list(graph:list) :
    for edge in graph : # for 'edge', so edge denoting the first element {0,1,10} and called the constructor and
        edge.print()    # then edge became an object and called it's method print(). We can also Edge(0,19).print()

def Main() :
    graph = []
    add_edge(graph, 0, 1, 10)
    add_edge(graph, 0, 3, 30)
    add_edge(graph, 0, 5, 20)
    add_edge(graph, 1, 3, 20)
    add_edge(graph, 1, 5, 30)
    add_edge(graph, 2, 4, 20)
    add_edge(graph, 2, 5, 20)
    add_edge(graph, 3, 5, 30)
    add_edge(graph, 4, 5, 10)

    print_adjacency_list(graph)
    print()

    graph.sort()

    print('After sorting based on the cost')
    print_adjacency_list(graph)

if __name__ == '__main__' :
    Main()