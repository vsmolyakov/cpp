#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
    Graph(int V);
    void add_edge(int v, int w);
    void BFS(int s);

private:
    int V; //number of vertices
    list<int> *adj; //pointer to adjacency list
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

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for (int i=0; i < V; ++i) {visited[i] = false;}

    queue<int> queue; //BFS queue

    //mark current node as visited
    visited[s] = true;
    queue.push(s);

    list<int>::iterator i;

    while(!queue.empty())
    {
        //deque a vertex from the q and print it
        s = queue.front();
        cout << s << " ";
        queue.pop();
        
        //queue all adjacent nodes of s if not visited
        for (i=adj[s].begin(); i!=adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                 visited[*i] = true;
                 queue.push(*i);
            }
        }

    }
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

    cout << "breadth first search (BFS) starting from vertex 2: " << endl;
    g.BFS(2);
    cout << endl;
   
    return 0;
}




