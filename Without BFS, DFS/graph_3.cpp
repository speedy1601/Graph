/*
Problem #3: Adjacency matrix with multiple edges
● What if we can’t just pick up one edge from the multiple edges? 
● Change the adjacency matrix representation somehow to be able to keep the multiple edges 
● Print the graph such that the edges of each node are printed first 
    ○ The order of the printed edges per (source) node doesn’t matter  
    ○ The graph edges are directed 
    ○ The graph weights are integer values
*/

/*
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
*/

#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<vector<int>>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from][to].push_back(cost);
}

void print(GRAPH &graph)
{
    int nodes = graph.size();
    for(int from=0; from<nodes; from++)
    {
        for(int to=0; to<nodes; to++)
        {
            for(int &weight : graph[from][to])
                cout << "From " << from << " to " << to << " the cost is " << weight << endl;
        }
    }
}

int main()
{
    int nodes, edges, from, to, cost;
    cin >> nodes >> edges;
    GRAPH graph(nodes, vector<vector<int>>(nodes));

    for(int edge = 0; edge<edges; edge++)
    {
        cin >> from >> to >> cost;
        add_directed_edge(graph, from, to, cost);
    }
    cout << endl;
    print(graph);
    return 0;
}
/* Space Complexity is O(V^2 + All The Weights) */