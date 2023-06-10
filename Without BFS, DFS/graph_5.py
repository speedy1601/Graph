'''
● Find a way to reduce this problem’s (graph_4) requirements (working on strings mainly) to the normal adjacency list
representation. In this way, the implemented algorithms can be used (e.g. to find shortest path) as they are 
    ○ Edge:  int from, to, weight; 
    ○ typedef vector<edge> GRAPH; 
    ○ void add_edge(GRAPH &graph, int from, int to, int cost) 
● For simplicity: Printing can be print in any order

Give the string 'from', 'to' an integer ID according to the map size() i.e. 0 to n-1.

Input :
5 9
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
Node California has neighbours :  
     (to Texas with the cost 30)  
     (to Texas with the cost 10)  
     (to Florida with the cost 75)
     (to Texas with the cost 35)  
     (to Pennsylvania with the cost 37)

Node Florida has neighbours :
     (to California with the cost 70)

Node Pennsylvania has neighbours :
     (to Florida with the cost 18)
     (to Florida with the cost 28)

Node Newyork has neighbours :
     (to California with the cost 35)
'''
class StrMapperID :
    def __init__(self):
        self.str_to_id = {}
        self.id_to_str = {}

    def to_id(self, fromm:str):
        if fromm in self.str_to_id :
            return self.str_to_id[fromm]
        
        id = len(self.str_to_id)
        self.str_to_id[fromm] = id
        self.id_to_str[id] = fromm
        return id

    def to_str(self, id:int):
        return self.id_to_str[id]

class Edge :
    def __init__(self, to:int, cost:int):
        self.to = to
        self.cost = cost

def add_directed_edge(graph, fromm:int, to:int, cost:int):
    graph[fromm].append(Edge(to, cost))

def add_undirected_edge(graph, fromm:int, to:int, cost:int):
    graph[fromm].append(Edge(to, cost))
    graph[to].append(Edge(fromm, cost))

def print_graph(graph, mapper:dict):
    for from_ in range(len(graph)):
        if len(graph[from_]) > 0:
            print(f'Node {mapper.to_str(from_)} has neighbours : ')
            for edge in graph[from_]:
                print(f"     (to {mapper.to_str(edge.to)} with the cost {edge.cost})")
            print()

def main():
    nodes, edges = map(int, input().split())
    graph = [[] for _ in range(nodes)] 
    mapper = StrMapperID()

    for _ in range(edges):
        fromm, to, cost = input().split()
        add_directed_edge(graph, mapper.to_id(fromm.capitalize()), mapper.to_id(to.capitalize()), int(cost))
    print()
    print_graph(graph, mapper)

if __name__ == '__main__':
    main()