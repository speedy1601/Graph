/*
Problem #1: Edge List representation
● An edge list representation is a collection of the graph edges. 
● For example, if we have 10 edges, then we have a vector of 10 edges 
● typedef vector<edge> GRAPH; 
● Implement a class edge that contains the relevant edges information 
        ○ The edges should be comparable based on the edge weight 
● void add_edge(GRAPH &graph, int from, int to, int cost) 
● void print_adjaceny_matrix(GRAPH &graph) 
● Read the edges into the data structure. Print them ordered based on cost 
*/

#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int from, to, weight;

    edge(int f, int t, int w) : from(f), to(t), weight(w) {}

    bool operator < (const edge &e) const
    {
        return weight < e.weight;
    }

    void print()
    {
        cout << "Edge ( " << from << " " << to << " " << weight << " )" << endl;
    }
};

typedef vector<edge> GRAPH;

void add_edge(GRAPH &graph, int from, int to, int cost)
{
    graph.push_back({from, to, cost});
}

void print_adjacency_list(GRAPH &graph)
{
    for(int edge = 0; edge<graph.size(); edge++)
        graph[edge].print();
}

int main()
{
    GRAPH graph;
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 0, 3, 30);
    add_edge(graph, 0, 5, 20);
    add_edge(graph, 1, 3, 20);
    add_edge(graph, 1, 5, 30);
    add_edge(graph, 2, 4, 20);
    add_edge(graph, 2, 5, 20);
    add_edge(graph, 3, 5, 30);
    add_edge(graph, 4, 5, 10);

    print_adjacency_list(graph); 
    cout << endl;

    sort(begin(graph), end(graph));

    print_adjacency_list(graph);
    return 0;
}

/*  
In this graph vector each element is {from, to, cost}, we have to push_back these 3 values not 
graph[from].push_back({to, cost}) as also we have to sort based on the cost. so in graph[from].push_back({to, cost})
we have to sort every row(from) and in graph.push_back({from, to, cost}) it's a lot easier.

sort(begin(graph), end(graph));  :: We also have to pass a comparison function like

bool cost_comparison(const edge &a, const edge &b)
{
    return a.weight < b.weight;
}
This function is same as the opeartor overloading function " bool operator < (const &edge) const {...} ".
So as we are sorting on the elements of the 'graph' where each element has the data type 'edge', 
when the sort function is called on the graph vector, it automatically uses the custom comparison operator 
(operator<) defined in the edge structure to compare the edges. The sort function invokes the comparison operator 
multiple times while rearranging the elements to determine their order. By repeatedly applying the comparison 
operator, the sort function can sort the edges in ascending order based on their weights.
*/