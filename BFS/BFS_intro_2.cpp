#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &edges, int n)
{
    vector<unordered_set<int>> graph(n);
    for(auto &a:edges)
        graph[a[0]].insert(a[1]),
        graph[a[1]].insert(a[0]);

    queue<int> q(deque<int>{0});
    vector<bool> visited(n);
    vector<int> label(n);
    visited[0] = true;
    int cur_node;

    for(int qsize = 1; qsize != 0; qsize = q.size())
    {
        for(int i=0; i<qsize; i++)
        {
            cur_node = q.front();
            q.pop();
            cout << cur_node <<  " ";    // current node 
            for(auto &v: graph[cur_node])
            {
                if(!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                    label[v] = label[cur_node] + 1;
                }
            }   
        }
    }
    cout << endl << endl << "Node   " << "Label No" << endl;
    for(int i=0; i<n; i++)
        cout << " " << i << "   :   " << label[i] << endl; 
}

int main()
{
    vector<vector<int>> edges = {{0,1},{0,2},{0,9},{1,5},{1,6},{2,4},{4,7},{6,8}, {7,3}};
    bfs(edges, 10);
    return 0;
}