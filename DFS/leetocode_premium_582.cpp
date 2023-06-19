/* 
leetocode premium 582
Question : Given pid (child nodes), ppid(parent nodes) and a node to kill. Kill the node and if you kill that node
           the node's child node will also get killed.

Input : 
pid = {1, 3, 10, 5, 7, 4}, ppid = {3, 0, 5, 3, 10, 7}, kill = 5

                0
              /
            3 ----- 5
           /         \
          1           10
                        \
                         7
                          \
                           4

Output : {5, 10, 7, 4} (in any order)

                0
              /
            3 
           /         
          1           
    
    
Explanation : Now If I kill 5, along 5 5's children 10 will also get killed and if 10 get killed then 10's children
will also get killed. So from 5 whatever nodes are able to be visited they all are killed and we've tp return these
kill able nodes. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void dfs(unordered_map<int, vector<int>> &graph, unordered_set<int> &visited, int parent_node)
    {
        visited.insert(parent_node);
        for(int &v : graph[parent_node])
        {
            if(!visited.count(v))
                dfs(graph, visited, v);
        }
    }

    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
    {
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<ppid.size(); i++) // add_directed_graph function
            graph[ppid[i]].push_back(pid[i]);
        
        unordered_set<int> visited;
        dfs(graph, visited, kill);
        return vector<int>(begin(visited), end(visited));
    }
};

int main()
{
    vector<int> pid = {1, 3, 10, 5, 7, 4}, ppid = {3, 0, 5, 3, 10, 7}; int kill = 5;    Solution s;
    vector<int> ans = s.killProcess(pid, ppid, kill);
    
    cout << kill << " has killed : ";
    for(int &v : ans) cout << v << " "; 
}