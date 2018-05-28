#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;

#define V 6

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    //returns true if there is a path between source s and sink t
    //in the residual graph, fills in parent to store the path
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s); visited[s] = true; parent[s] = -1;

    //BFS loop
    while (!q.empty())
    {
        int u = q.front(); q.pop();

        for (int v = 0; v < V; ++v)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                q.push(v); parent[v] = u; visited[v] = true;
            }
        }
    
    }

    return (visited[t] == true);
}

int edmonds_karp(int graph[V][V], int s, int t)
{
    //init residal graph with graph capacities
    int rGraph[V][V];

    for (int u=0; u<V; ++u)
        for (int v=0; v<V; ++v)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;

    //augment the flow while there is a path from s to t
    while (bfs(rGraph, s, t, parent))
    {
        //find min capacity edge along path found by BFS
        int path_flow = INT_MAX;
        for (int v=t; v!=s; v=parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
       
        //update capacities of forward and backward edges
        for (int v=t; v != s; v = parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    //adjacency matrix
    int graph[V][V] = {{0, 16, 13,  0,  0,  0},
                       {0,  0, 10, 12,  0,  0},
                       {0,  4,  0,  0, 14,  0},
                       {0,  0,  9,  0,  0, 20},
                       {0,  0,  0,  7,  0,  4},
                       {0,  0,  0,  0,  0,  0}
                      };

    cout << "Max Flow Emdonds Karp Algorithm" << endl;
    int mf = edmonds_karp(graph, 0, 5);
    cout << "max flow is " << mf << endl;

    return 0;
}






