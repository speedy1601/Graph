/*
Problem #2: Adjacency Hashset Representation
● Can we iterate on neighbours efficiently (O(Degree )), while still checking whether an edge exists or not in O(1)?
  The best of 2 worlds? 
● Simply, yes. Instead of a list per node, use a hashset! 
● typedef vector<unordered_set<int>> GRAPH; 
   ○ Assume it is unweighted graph 
- Implement : void add_directed_edge(...), void add_undirected_edge, void print(...)
*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<unordered_set<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from].insert(to);
}

void add_undirected_edge(GRAPH &graph, int from, int to)
{
    graph[from].insert(to);
    graph[to].insert(from);
}

void print(GRAPH &graph)
{
    int i = 0;
    for(unordered_set<int> &u: graph)
    {
        cout << i++ << " has " << u.size() << " neighbours : ";
        for(const int &v : u)
            cout << v << " ";
        cout << endl;
    }
}

int main()
{
    int nodes, edges, from, to;
    cin >> nodes >> edges;

    GRAPH graph(nodes);
    for(int i=0; i<edges; i++)
    {
        cin >> from >> to;
        add_directed_edge(graph, from, to);
    }
    cout << endl;
    print(graph); 
    return 0;
}

/*

6 7
2 1
2 5
2 0
2 3
0 5
1 4
5 4

Output
Node 0 has 1 neighbors: 5
Node 1 has 1 neighbors: 4
Node 2 has 4 neighbors: 3 0 1 5
Node 3 has 0 neighbors:
Node 4 has 0 neighbors:
Node 5 has 1 neighbors: 4

Space Complexity is O(E) E = Total Edges
Time complexity
	O(1) for add/remove/check edge
	O(neighbours) for iterating on neighbors

Disadvantages
	- No order guarantee for edges
	- Impractical for multiple edges  (we may do workarounds)
	- Hash tables extra memory
	- Like any hash tables, more caution to properly deal with the load (load factor)

 */
