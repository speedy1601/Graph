/*
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
*/

#include<bits/stdc++.h>
using namespace std;

struct edge
{
    string to;
    int cost;

    edge(string _to, int _cost) : to(_to), cost(_cost) {}

    bool operator < (const edge &other) const 
    {
        return to == other.to ? cost < other.cost : to < other.to;
    }

};

typedef map<string, multiset<edge>> GRAPH;
string capitalize(string s)
{
    s[0] = toupper(s[0]);
    return s;
}

void add_directed_edge(GRAPH &graph, string from, string to, int cost)
{
    graph[capitalize(from)].insert({capitalize(to),cost});
}

void print(GRAPH &graph)
{
    for(const auto &node : graph)
    {
        cout << "Flights from " << node.first << " : " << endl;
        for(const edge &e : node.second)
            cout << "        To " << e.to << " with the cost " << e.cost << endl;
        cout << endl;
    }
}

int main()
{
    int nodes, edges, cost;
    cin >> nodes >> edges;
    GRAPH graph;
    string from, to;

    for(int edge = 0; edge < edges; edge++)
    {
        cin >> from >> to >> cost;
        add_directed_edge(graph, from, to, cost);
    }
    cout << endl;
    print(graph);
    return 0;
}