#include <iostream>
#include <climits>
using namespace std;

#define V 4
#define INF 32000 

void floyd_warshall(int graph[][V], int dist[][V], int parent[][V])
{
    //dist[i][j] stores minimum distances between every pair of nodes (i,j)
    //dist[i][j] init to be the same as input graph
    //we expect dist[i][i] = 0 and dist[i][j] = INF if no edge between i and j
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            dist[i][j] = graph[i][j];

    //DP: either include vertex k or don't include it
    for (int k = 0; k < V; ++k)
    {
        //iterate through source vertices
        for (int i = 0; i < V; ++i)
        {
            //iterate through destination vertices
            for (int j = 0; j < V; ++j)
            {
                //dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
}

void print_solution(int dist[][V])
{
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void print_path(int i, int j, int p[][V])
{
    if (i != j) print_path(i, p[i][j], p);
    printf(" %d", j);
}

int main()
{
    //adjacency matrix
    //Adj[i][j] = 0 for all i = j and 
    //Adj[i][j] = INF if there is no edge between i and j
    int graph[V][V] = {{0,   5,   INF,  10},
                       {INF, 0,   3,   INF},
                       {INF, INF, 0,     1},
                       {INF, INF, INF,   0}
                      };
    cout << "All Pairs Shortest Paths (APSP) Floyd-Warshall: " << endl;

    int APSP[V][V], parent[V][V];
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            parent[i][j] = i;

    floyd_warshall(graph, APSP, parent);

    print_solution(APSP);

    printf("path from 0 to 3 with cost %d: ", APSP[0][3]);
    print_path(0, 3, parent);
    cout << endl;

    return 0;
}




