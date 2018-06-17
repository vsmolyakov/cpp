#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
public:
    Graph (int V);
    void add_edge(int v, int w);
    void topological_sort();

private:
    int V;
    list<int> *adj;
    void topological_sort_util(int v, bool visited[], stack<int> &Stack);
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

void Graph::topological_sort_util(int v, bool visited[], stack<int>& Stack)
{
   //mark current node as visited
   visited[v] = true;

   //DFS
   list<int>::iterator i;
   for (i = adj[v].begin(); i != adj[v].end(); ++i)
   {
       if (!visited[*i])
           topological_sort_util(*i, visited, Stack);
   }

   //push current vertex onto stack
   Stack.push(v);
}

void Graph::topological_sort()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    for (int i = 0; i < V; ++i) {visited[i] = false;}

    //call DFS + stack from all vertices V
    for (int i = 0; i < V; ++i)
    {
        if (visited[i] == false)
            topological_sort_util(i, visited, Stack);
    }

    //print topological sort stored in the stack
    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    Graph g(6);
    g.add_edge(5, 2);
    g.add_edge(5, 0);
    g.add_edge(4, 0);
    g.add_edge(4, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);

    cout << "topological order:\n";
    g.topological_sort();
    cout << endl;

    return 0;
}







