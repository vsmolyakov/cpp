#include <iostream>
#include <list>
using namespace std;

class Graph
{
public:
    Graph (int V);
    void add_edge(int v, int w);
    void DFS (int V);

private:
    int V; // number of vertices
    list<int> * adj; //pointer to adj list

    void DFS_util(int v, bool visited[]);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::add_edge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS_util(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    //recurse for all adjacent vertices
    //if they are not visited (to avoid cycles)
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
            DFS_util(*i, visited);
    }
}

void Graph::DFS(int v)
{
    //init all vertices as not visited
    bool *visited = new bool[V];
    for (int i=0; i < V; ++i)
    {
        visited[i] = false;
    }

    //call recursive helper function
    DFS_util(v, visited);
}

int main()
{
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);

    cout << "depth first search (DFS) starting from vertex 2: " << endl;
    g.DFS(2);
    cout << endl;

    return 0;
}





