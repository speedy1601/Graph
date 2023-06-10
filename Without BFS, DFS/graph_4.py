'''
Problem #1: Adjacency-based repr for flights v1
● In the airports, there are many flights (from, to, cost) 
    ○ Where from and to are strings (no spaces) and cost is an integer value 
● Represent the directed graph based on adjacency style 
    ○ There are multiple edges ● Your print function must do the following: 
    ○ Flights from are printed sorted (alphabetical order) 
    ○ For each from airport: print the to cities based on 
        ■ alphabetical order 
        ■ If there is a tie, the one with smaller cost first 

Input : 
9
california texas 30
california texas 10
florida california 70
california florida 75
pennsylvania florida 18
pennsylvania florida 28
newyork california 35
california texas 35
california pennsylvania 37

Output :
Flights from California : 
        To Florida with the cost 75     
        To Pennsylvania with the cost 37
        To Texas with the cost 10       
        To Texas with the cost 30       
        To Texas with the cost 35

Flights from Florida :
        To California with the cost 70

Flights from Newyork :
        To California with the cost 35

Flights from Pennsylvania :
        To Florida with the cost 18
        To Florida with the cost 28
'''
from sortedcontainers import SortedDict, SortedSet

class Edge :
    def __init__(self, to:str, cost:int):
        self.to = to
        self.cost = cost
    
    def __lt__(self, other):
        return (self.to, self.cost) < (other.to, other.cost)

def add_directed_edge(graph, fromm:str, to:str, cost:int):
    fromm, to = fromm.capitalize(), to.capitalize()
    graph.setdefault(fromm, SortedSet()).add(Edge(to, cost))

def print_graph(graph):
    for node, edges in graph.items(): 
        print(f"Flights From {node} :")     
        for e in edges:
            print(f"       To {e.to} with the cost {e.cost}")
        print()

def Main():
    graph = SortedDict() 
    n = int(input())

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

'''  In the code graph.setdefault(fromm, SortedSet()), the setdefault() method is used to retrieve the value for the 
given key fromm from the graph dictionary. If the key is present in the dictionary, the method returns its 
corresponding value. If the key is not present, the method sets the key to the default value provided (SortedSet() 
in this case) and returns that default value.    
So here it's returning the empty set if the key(fromm) doesn't exist OR the existing set if key(fromm) exists.
any set.add(value) is how to to insert value in set. 
Instead of writing graph.setdefault(fromm, SortedSet); graph[from].add(Edge(to,cost)); Just write in a single line 
graph.setdefault(fromm, SortedSet()).add(Edge(to, cost)) == set.add(Edge(to, cost))   '''

''' You can't write graph = SortedDict(SortedSet) BUT graph = defaultdict(sorted) because -

defaultdict is a subclass of dict that automatically creates and initializes a new entry with a default value if the 
key doesn't exist when accessed. The defaultdict implementation doesn't rely on key comparisons or sorting, so it can 
use SortedSet as the default value without any issues.
On the other hand, SortedDict in the sortedcontainers library is specifically designed for maintaining a sorted order
of keys. It requires a comparison function or key function to determine the ordering of the keys. It doesn't directly
support nested sorted containers like SortedSet as the value type. Therefore, using SortedSet directly as the value 
type for SortedDict won't work as expected.'''
