/*
Input :

6 14
0 1
0 3
1 2
1 5
2 0
2 3
3 0
3 4
4 2
4 4
4 5
5 0
5 3
5 5

Output :

        Direct  Paths       
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 

1 -> 2 -> 0 -> 3 -> 4 -> 5 -> 

2 -> 0 -> 1 -> 5 -> 3 -> 4 -> 

3 -> 0 -> 1 -> 2 ->                 <---  The difference lies in 3 no node. staright_path() prints a direct path
                                        | from the parent_node to the end reachable node. 
4 -> 2 -> 0 -> 1 -> 5 -> 3 ->           |    
                                        | 3 : [0, 4]. From 3 we can go 0 and 4. 3 is the parent/main node. We go to
5 -> 0 -> 1 -> 2 -> 3 -> 4 ->           | the vector of graph[3] (0,4) and checked if 0 has visited, NO! so 3 -> 0 
                                        | we could also go by 3 -> 4 but we're taking only the first UNVISITED node
      DFS Reacable Nodes                | in straight_path() as WE INTEND TO PRINT A PATH/ROADMAP like from 3 to 2
0 -> 1 -> 2 -> 3 -> 4 -> 5 ->           | we can go in this path : 3 -> 0 -> 1 -> 2 . As 2 : [0,3] we can't go from
                                        | 2 to any road/node.
1 -> 2 -> 0 -> 3 -> 4 -> 5 ->           |  
                                        | 
2 -> 0 -> 1 -> 5 -> 3 -> 4 ->           | 
                                        |
3 -> 0 -> 1 -> 2 -> 5 -> 4 ->       <---  dfs saying you can go from 3 to 2 by 3 -> 0 -> 1 -> 2 , 
                                                                from 3 to 5 by 3 -> 0 -> 1 -> 5 but we can't 
4 -> 2 -> 0 -> 1 -> 5 -> 3 ->             understand this clearly (as there is 2 before 5) from the dfs cause DFS 
                                          PRINTS ONLY THE REACHABLE NODES, NOT PATH! 
5 -> 0 -> 1 -> 2 -> 3 -> 4 ->        

A somewhat details explanation added in notebook
*/

#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
}

void dfs(const GRAPH &graph, vector<bool> &visited, int parent_node)
{
    visited[parent_node] = true;
    for(const int &child_node : graph[parent_node])
    {
        if(visited[child_node] == false)
        {
            cout << child_node << " -> ";
            dfs(graph, visited, child_node);
        }
    }
}

// reacability function prints ALL THE REACHABLE NODES by dfs for every node(i)
void reachability(const GRAPH &graph)
{
    for(int i=0; i<graph.size(); i++)
    {
        vector<bool> visited(graph.size());
        cout << i << " -> ";
        dfs(graph, visited, i);
        cout << endl << endl;
    }
}
// Unlike dfs() who prints ALL THE REACHABLE NODES, straight_path() prints PATH/ROADMAP from the parent road
// it doesn't go back to the caller function   
void straight_path(const GRAPH &graph, int parent_node)   
{
    unordered_set<int> visited;
    while(true)
    {
        visited.insert(parent_node);
        auto it = graph[parent_node].begin();
        for(; it != graph[parent_node].end(); it++)
        {
            if(!visited.count(*it))
            {
                cout << *it << " -> ";
                parent_node = *it;
                break;
            }
        }
        if(it == graph[parent_node].end())
            return;
    }
}

void first_paths(const GRAPH &graph)
{
    for(int i=0; i<graph.size(); i++)
    {
        cout << i << " -> ";
        straight_path(graph, i);
        cout << endl << endl;
    }
}

void print_graph(const GRAPH &graph)
{
    for(const vector<int> &arr : graph)
    {
        for(const int &v : arr)
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
    
    cout << "        Direct  Paths" << endl;
    first_paths(graph);  
    cout << "        DFS Reacable Nodes" << endl;
    reachability(graph);
}

/*
We printed reachable-nodes in dfs for every node(i). We will find the TC and SC for a single node.
Time  Complexity : O(nodes + edges) as at we visit every node and every edges at worst case.
Space Complexity : O(nodes)

For reachability() Space Complexity is O(nodes + local space for stack) i.e. for every node a bool vector, so nodes
time bool vector created here + stack call included.
*/