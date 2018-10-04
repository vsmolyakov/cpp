#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

typedef pair<int, int> ipair;

class Graph
{
public:
    Graph(int V, int E){this->V = V; this->E = E;}

    void add_edge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }

    int kruskalMST();

private:
    int V, E;
    vector<pair<int, ipair>> edges; //{cost, {src, dst}} 
};

class UnionFind
{
public:
   UnionFind(int n)
   {
       this->n = n;
       parent = new int[n+1];
       rnk = new int[n+1];

       //init all vertices to different sets
       //and set rank to zero
       for (int i = 0; i <= n; ++i)
       {
            rnk[i] = 0;
            parent[i] = i;
       }
   }

   //find the parent of node u and apply path compression
   //i.e. make u point directly to the root to minimize rank
   int find(int u)
   {
       if (u != parent[u])
           parent[u] = find(parent[u]);

       return parent[u];
   }
     
   //union by rank (attach shorter tree to a taller one)
   void merge(int x, int y)
   {
       //retrieve representatives (root) of each set
       x = find(x);
       y = find(y);

       if (rnk[x] > rnk[y])
           parent[y] = x;
       else
           parent[x] = y;

       if (rnk[x] == rnk[y])
           rnk[y]++;
   }

private:
    int n;
    int *parent, *rnk;
};

int Graph::kruskalMST()
{
    int mst_wt = 0; //init

    //sort edges in increasing order by weight
    sort(edges.begin(), edges.end());

    //create disjoint sets
    UnionFind ds(V);

    //iterate through all sorted edges
    vector<pair<int,ipair>>::iterator it;
    for (it=edges.begin(); it!=edges.end(); ++it)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        //check if selected edge creates a cycle
        //i.e. if u and v belong to the same connected component
        if (set_u != set_v)
        {
            cout << u << " - " << v << endl;
            mst_wt += it->first;
            ds.merge(set_u, set_v);
        }
    
    }

    return mst_wt;
}

int main()
{
    int V = 9, E = 14;
    Graph g(V, E);

    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);

    cout << "MST egdes (Kruskal): " << endl;
    int mst_wt = g.kruskalMST();
    cout << "MST weight: " << mst_wt << endl;

    return 0;
}
