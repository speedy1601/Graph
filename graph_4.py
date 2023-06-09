from collections import defaultdict
from sortedcontainers import SortedSet

class Edge :
    def __init__(self, to:str, cost:int):
        self.to = to
        self.cost = cost
    
    def __lt__(self, other):
        return (self.to, self.cost) < (other.to, other.cost)

def add_directed_edge(graph, from_:str, to:str, cost:int):
    graph[from_.capitalize()].add(Edge(to.capitalize(), cost))

def print_graph(graph):
    for node, edges in sorted(graph.items()): # as dict store in unorder. The 2nd values (Edge()) are sorted.
        print(f"Flights From {node} :")       # Just the keys are not sorted. Simply print the sorted ones.
        for e in edges:
            print(f"       To {e.to} with the cost {e.cost}")
        print()

def Main():
    graph = defaultdict(SortedSet) # We're not passing any empty set value (SortedSet()), we're saying graph will
    n = int(input())               # have SortedSet type value in its second argument 

    for _ in range(n):
        fromm, to, cost = input().split()
        add_directed_edge(graph, fromm, to, int(cost)) 

    print()
    print_graph(graph)

if __name__ == '__main__':
    Main()

'''   The expression (self.to, self.cost) < (other.to, other.cost) creates tuples (self.to, self.cost) and 
(other.to, other.cost) for both instances, and then compares them lexicographically. This means it first compares 
self.to with other.to, and if they are equal, it compares self.cost with other.cost. The result of this 
comparison is then returned.    '''


'''
You can also use OrderedDict with the following changes :

from collections import OrderedDict

def add_directed_edge(graph, _from, to, cost):
    graph.setdefault(_from, SortedSet()).add(Edge(to, cost))

graph = OrderedDict()
'''

'''
graph.setdefault(_from, SortedSet()).add(Edge(to, cost)) is same as :

if _from not in graph :
    graph[_from] = SortedSet()
graph[_from].add(Edge(to, cost))

You cannot directly write graph = OrderedDict(SortedSet()) to represent that every value is a sorted set in the 
ordered dictionary. The OrderedDict constructor does not accept default values for its elements. It creates an empty 
ordered dictionary by default.
'''