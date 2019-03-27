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

bool isValid(Graph const &graph, vector<int> color, int v, int c)
{
    for (int u : graph.adj_list[v])
        if (color[u] == c) {return false;}

    return true;
}

void kColorable(Graph const &graph, vector<int>& color, int K, int v, int N)
{
    //if all colors are assigned, print the solution
    if (v == N)
    {
        for (int v = 0; v < N; ++v)
            cout << color[v] << " ";
        cout << endl;
        return;
    }

    //try all possible combinations of available colors
    for (int c = 1; c <= K; ++c)
    {
        if (isValid(graph, color, v, c))
        {
            //assign color c to vertex v
            color[v] = c;

            //recurse for the next vertex
            kColorable(graph, color, K, v+1, N);

            //backtrack
            color[v] = 0;
        }
    }
}

int main()
{
    //complete graph with 4 nodes
    int N = 6;
    vector<Edge> edges = 
    {
        {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}
    };

    //create graph from edge list
    Graph g(edges, N);

    int K = 3; // number of colors 
    
    vector<int> color(N, 0);
    
    cout << "all k-colorable configurations of the graph" << endl;
    cout << "for k = " << K <<  ":" << endl;
    kColorable(g, color, K, 0, N);

    return 0;
}
