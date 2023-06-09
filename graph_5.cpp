/*
● Find a way to reduce this problem’s (graph_4) requirements (working on strings mainly) to the normal adjacency list
representation. In this way, the implemented algorithms can be used (e.g. to find shortest path) as they are 
    ○ Edge:  int from, to, weight; 
    ○ typedef vector<edge> GRAPH; 
    ○ void add_edge(GRAPH &graph, int from, int to, int cost) 
● For simplicity: Printing can be print in any order

Give the string 'from', 'to' an integer ID according to the map size() i.e. 0 to n-1.

Input :
5 9
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
Node California has neighbours :  
     (to Texas with the cost 30)  
     (to Texas with the cost 10)  
     (to Florida with the cost 75)
     (to Texas with the cost 35)  
     (to Pennsylvania with the cost 37)

Node Florida has neighbours :
     (to California with the cost 70)

Node Pennsylvania has neighbours :
     (to Florida with the cost 18)
     (to Florida with the cost 28)

Node Newyork has neighbours :
     (to California with the cost 35)
*/
#include<bits/stdc++.h>
using namespace std;

class StrMapperID
{
    private:
        unordered_map<string, int> str_to_id;
        unordered_map<int, string> id_to_str;
    public:
        int to_id(string from)
        {
            if(str_to_id.count(from) > 0)
                return str_to_id[from];
            // if part is important bcz otherwise if a key exists and we overwrite its value by str_to_id.size(),
            int id = str_to_id.size();      // we will have unexpected result.
            str_to_id[from] = id;
            id_to_str[id] = from;
            return id;
        }

        string to_str(int id)
        {
            return id_to_str[id];
        }
};

struct edge
{
    int to, cost;
};

typedef vector<vector<edge>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from].push_back({to, cost});
}
void add_undirected_edge(GRAPH &graph, int from, int to, int cost)
{
    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
}

void print_graph(const GRAPH &graph, StrMapperID &mapper)
{
    for(int i=0; i<graph.size(); i++)
    {
        if(graph[i].size() > 0)
        {
            cout  << "Node " << mapper.to_str(i) << " has neighbours : " << endl;
            for(const edge &e : graph[i])
                cout << "     (to " << mapper.to_str(e.to) << " with the cost " << e.cost << " )" << endl;
            cout << endl;
        }
    }
}

int main()
{
    int nodes, edges, cost;
    string from, to;
    cin >> nodes >> edges; // make sure string 'from' doesn't have <= unique values than nodes.
    
    GRAPH graph(nodes);
    StrMapperID mapper;

    for(int i=0; i<edges; i++)
    {
        cin >> from >> to >> cost;
        add_directed_edge(graph, mapper.to_id(from), mapper.to_id(to), cost);
    }
    cout << endl;
    print_graph(graph, mapper);
}