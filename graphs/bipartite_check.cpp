#include <iostream>
#include <queue>
using namespace std;

#define V 4

bool is_bipartite(int G[][V], int src)
{
    int color[V];
    for (int i=0; i<V; ++i) {color[V] = -1;}

    color[src] = 1;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front(); q.pop();

        if (G[u][u] == 1){return false;} //self-loop

        //adjacency matrix: find all neighbors of u
        for (int v=0; v<V; ++v)
        {
            if (G[u][v] && color[v] == -1)
            {
                //assign alternate color
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (G[u][v] && color[u] == color[v])
            {
                //neighboring nodes have the same color
                return false;
            }
        }
    
    }

    return true;
}

int main()
{
    //adjacency matrix
    int G[][V] = {{0, 1, 0, 1},
                  {1, 0, 1, 0},
                  {0, 1, 0, 1},
                  {1, 0, 1, 0},
                 };

    cout << "undirected graph G with even cycle" << endl;
    cout << "Q: Is it bipartite?" << endl;
    is_bipartite(G, 0) ? cout << "A: Yes\n" : cout << "A: No\n";

    return 0;
}
