/*
Input :
6 9
2 1           5      4     1 5 0 3           3 2     4   ---> vector of edges for every 'from'
2 5          ---    ---   ---------   ---   -----   ---
2 0           0      1        2        3      4      5   ---> index (from)
2 3
0 5
1 4
5 4
4 3
4 2

Ouput :
0 5 4
1 4 3
1 4 2
2 1 4
2 5 4
2 0 5
4 2 1            index 4 has 3, 2.. For 3 in the index 3 there is no edge. So there's no 4 3 _
4 2 5
4 2 0
4 2 3
5 4 3
5 4 2
*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
void add_directed_edge(GRAPH &graph, int from, int to)
{
    graph[from].push_back(to);
}

void print_paths_len_2(GRAPH &graph)
{
    for(int i=0; i<graph.size(); i++)
    {
        for(const int &v : graph[i])
        {
            for(const int &w : graph[v])
                cout << i << " " << v << " " << w << endl;
        }
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
    print_paths_len_2(graph);
}