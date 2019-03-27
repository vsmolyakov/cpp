#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int src, dst;
};

class Graph
{
public:
    vector<int> *adj_list;

    Graph(vector<Edge> const &edges, int N)
    {
        adj_list = new vector<int>[N];

        for (int i = 0; i < (int) edges.size(); ++i)
        {
            int src = edges[i].src;
            int dst = edges[i].dst;
            adj_list[src].push_back(dst);
            adj_list[dst].push_back(src);
        }
    }
};

void hamiltonian_paths(Graph const& g, int v, vector<bool> visited, 
                       vector<int> &path, int N)
{
    if ((int) path.size() == N)
    {
        //print hamiltonian path
        for (int i : path) {cout << i << " ";}
        cout << endl;
        return;
    }

    //check if every edge starting from vertex v leads to
    //a solution or not
    for (int w : g.adj_list[v])
    {
        //process only unvisited vertices as Hamiltonian
        //path visits each vertex exactly once
        if (!visited[w])
        {
            visited[w] = true;
            path.push_back(w);

            //check if adding vertex w to the path leads
            //to a solution or not
            hamiltonian_paths(g, w, visited, path, N);

            //backtrack
            visited[w] = false;
            path.pop_back();
        
        }
    }
}

int main()
{
    //complete graph with 4 nodes
    int N = 4;
    vector<Edge> edges = 
    {
        {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}
    };

    //create graph from edge list
    Graph g(edges, N);

    int start = 0; // starting node
    
    //add starting node to path
    vector<int> path;
    path.push_back(start);

    //mark start node as visited
    vector<bool> visited(N);
    visited[start] = true;

    cout << "complete graph hamiltonian paths: " << endl;
    hamiltonian_paths(g, start, visited, path, N);

    return 0;

}
