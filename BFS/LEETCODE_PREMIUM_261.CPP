#include <bits/stdc++.h>
using namespace std;

// bool bfs(vector<unordered_set<int>> &graph, int n)   // 2nd way
// {
//     queue<int> q(deque<int>{0});
//     vector<bool> visited(n);
//     visited[0] = true;
//     int cur_node;

//     for(int qsize = 1; qsize != 0; qsize = q.size())
//     {
//         for(int i=0; i<qsize; i++)
//         {
//             cur_node = q.front();
//             q.pop(); 
//             for(auto &v: graph[cur_node])
//             {
//                 if(v > cur_node)
//                 {
//                     if(visited[v])
//                         return false;
//                     q.push(v);
//                     visited[v] = true;
//                 }
//             }   
//         }
//     }

//     return true; 
// }

bool bfs(vector<unordered_set<int>> &graph, int n)
{
    queue<int> q(deque<int>{0});
    vector<bool> visited(n);
    visited[0] = true;
    int cur_node;

    while(!q.empty())
    {
        cur_node = q.front();
        q.pop();
        for(auto &v: graph[cur_node])
        {
            if(v>cur_node)
            {
                if(visited[v])
                    return false;
                q.push(v);
                visited[v] = true;
            }
        }
    }
    return true;
}

bool validTree(int n, vector<vector<int>> &edges)
{
    vector<unordered_set<int>> graph(n);
    for(auto &a:edges)
        graph[a[0]].insert(a[1]),
        graph[a[1]].insert(a[0]);
    return bfs(graph, n);
}
int main()
{
    vector<vector<int>> edges = {{0,1},{0,2},{0,9},{1,5},{1,6},{2,4},{4,7},{6,8}, {5,8}, {7,3}};
    int n = 10;
    cout << (validTree(n, edges)? "Valid Tree" : "Non-valid Tree");
    return 0;
}