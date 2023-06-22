/*
Input : 
nodes = 6, edges = {{1,2}, {3,4}, {5,3}, {4,5}};   Note : it's an UNDIDIRECTED GRAPH

Output :
3

                            0       |--->
                                         
                        1 ----- 2   |--->   These 3 part are fully isolated
                                               
                        3 ----- 4   |    
                          \   /     |--->
                            5       |     
                            
Input : 
nodes = 6, edges = {{1,2}, {3,4}, {5,3}, {2,3}, {4,5}};
                                          
Output :
2

                            0       |--->
                                         
                        1 ----- 2   |  
                              /     |                
                            /       |      These 2 part are fully isolated
                          /         |---->          
                        3 ----- 4   |
                          \   /     |
                            5       |     
                                              
*/
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    void build_graph_from_edges(const vector<vector<int>> &edges, vector<vector<int>> &graph)
    {
        for(const vector<int> &arr : edges)
        {
            graph[arr[0]].push_back(arr[1]);
            graph[arr[1]].push_back(arr[0]);
        }
    }

    void dfs(const vector<vector<int>> &graph, vector<bool> &visited, int start)
    {
        visited[start] = true; 
        for(const int &child : graph[start])
        {
            
            if(visited[child] == false)
                dfs(graph, visited, child);
        }
    }

    int count_components(const vector<vector<int>> &graph)
    {
        int nodes = graph.size(), count = 0;
        vector<bool> visited(nodes, false);
        for(int i=0; i<nodes; i++) // nodes 0 to n-1
        {
            if(visited[i] == false) // if the node still unvisited even after calling dfs (except for node 0)
            {
                count++;
                dfs(graph, visited, i);
            }
        }
        return count;
    }

	int countComponents(int nodes, vector<vector<int>> &edges) 
    {
		vector<vector<int>> graph(nodes);
        build_graph_from_edges(edges, graph);
        return count_components(graph);
	}
};

int main()
{
    int nodes = 6;
    vector<vector<int>> edges = {{1,2}, {3,4}, {5,3}, {2,3}, {4,5}};
    Solution s;
    cout << s.countComponents(nodes, edges);
}
