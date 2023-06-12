/*
Problem #1: Find a sink   (GRAPH IS AN ADJACENCY MATRIX)
● In a directed graph of N nodes, a universal sink is a vertex with in-degree N-1 and out-degree 0. 
    Return 0-based index for node i that is sink or -1 if none 
● Your program should read multiple graphs as following 
    ○ First read integer T for T test cases 
    ○ Then for each test case read 2 numbers: nodes and edges 
    ○ Then read the edges (0-based) 

Input & Output :
3
6 5 
0 3
1 3
2 3
4 3
5 3

3

6 9
0 3
1 3
2 3
4 3
3 5
0 5
1 5
2 5
4 5

5

5 4
0 1
1 2
2 3
3 4

-1*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from][to] = 1;
}

int index_of_universal_sink(const GRAPH &graph)
{
    int l, c = 0, i, n = graph.size();
    for(int r=0; r<n; r++)
    {
        l = lower_bound(begin(graph[r]), end(graph[r]), 1) - begin(graph[r]);
        if(l == n) i = r, c++; 
    }
    return c == 1 ? i : -1;
}

void print(GRAPH &graph)
{
    for(auto arr : graph)
    {
        for(int v : arr)
            cout << v << " ";
        cout << endl;
    }
}

int main()
{
    int nodes, edges, T, from, to;
    cin >> T;
    while(T--)
    {
        cin >> nodes >> edges;
        GRAPH graph(nodes, vector<int>(nodes));
        for(int i=0; i<edges; i++)
        {
            cin >> from >> to;
            add_directed_edge(graph, from, to);
        }
        cout << endl;
        cout << index_of_universal_sink(graph) << endl;
        cout << endl;
    }
}