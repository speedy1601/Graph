/*
Input : 
m = 3, n = 4           0  1  2      each value has neighbours : left, right, top, bottom 
                       3  4  5      for 3 : 4 0 6
                       6  7  8
                       9  10 11 
Output :
Node 0 has neighbours : 1 4      
Node 1 has neighbours : 0 2 5    
Node 2 has neighbours : 1 3 6    
Node 3 has neighbours : 2 7      
Node 4 has neighbours : 5 0 8    
Node 5 has neighbours : 4 6 1 9  
Node 6 has neighbours : 5 7 2 10 
Node 7 has neighbours : 6 3 11   
Node 8 has neighbours : 9 4      
Node 9 has neighbours : 8 10 5   
Node 10 has neighbours : 9 11 6  
Node 11 has neighbours : 10 7   
*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
void add_neighbours(GRAPH &graph, int m, int n)
{
    int r, c, v=0;
    for(r=1; r<=m; r++)
    {
        for(c=1; c<=n; c++)
        {
            if(c != 1)   graph[v].push_back(v-1);     // left
            if(c != n)   graph[v].push_back(v+1);    //  right
            if(r != 1)   graph[v].push_back(v-n);   //   top
            if(r != m)   graph[v].push_back(v+n);  //    bottom
            v++;
        }
    }
}

void print_neighbours(GRAPH &graph)
{
    for(int i=0; i<graph.size(); i++)
    {
        cout << "Node " << i << " has neighbours : ";
        for(const int &v : graph[i])
            cout << v << " ";
        cout << endl;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    GRAPH graph(m*n);
    add_neighbours(graph, m, n);
    print_neighbours(graph);
    return 0;
}

/*   If you just want to print them.

void print_neighbours(int m, int n)
{
    int r, c, v=0;
    for(r=1; r<=m; r++)
    {
        for(c=1; c<=n; c++)
        {
            cout << "Node " << v << " has neighbours : ";

            if(c != 1)   cout << v-1 << " ";     // left
            if(c != n)   cout << v+1 << " ";    //  right
            if(r != 1)   cout << v-n << " ";   //   top
            if(r != m)   cout << v+n << " ";  //    bottom
            v++;
            cout << endl;
        }
    }
}
*/