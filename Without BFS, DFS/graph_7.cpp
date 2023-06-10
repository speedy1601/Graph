/*
Write a program that reads a directed unweighted graph 
    ○ Read N nodes and M edges then read the M edges (from, to). So from = index, to = value
Then read integer Q, for number of queries, then read Q integers. Each query is a node number; we want to list the 
path start from it until the last possible node.
NOTE : THERE WILL BE ONLY A SINGLE EDGE FOR A SINGLE NODE e.g. for 4 it's just 1.

Input & Output

6 5       6 nodes 5 edges                    0
4 1  --                                      |
1 2    |                                1 ---|---> 2
5 3    |-- 5 edges                      ↑---------..
0 5    |                                3 ---|---> 4 
3 4  --                                 ↑    ↓ 
4    -- 4 quiries                       |--- 5 
0    -- path
0 5 3 4 1 2 -- show_path(..)
3    -- path
3 4 1 2     -- show_path(..)
1    -- path
1 2         -- show_path(..)
2    -- path
2           -- show_path(..)
*/
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from] = to;
}

void show_path(const GRAPH &graph, int node_no)
{
    cout << node_no << " ";
    while(graph[node_no] != -1)
    {
        cout << graph[node_no] << " ";
        node_no = graph[node_no];
    }
    cout << endl;
}

int main()
{
    int nodes, edges, from, to;
    cin >> nodes >> edges;
    GRAPH graph(nodes, -1);
    for(int i=0; i<edges; i++)
    {
        cin >> from >> to;
        add_directed_edge(graph, from, to);
    }
    
    int quiries, node_no;
    cin >> quiries;
    for(int i=0; i<quiries; i++)
    {
        cin >> node_no;
        show_path(graph, node_no);
    }
    return 0;
}