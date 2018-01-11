#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <class T>
class graph
{
public:
    explicit graph() {}
    
    template <class InputIterator>
    explicit graph(InputIterator begin, InputIterator end)
        : nodes(begin, end) {}

    void add_edge(T src, T dst)
    {
        nodes.insert(src);
        nodes.insert(dst);
        edges[src].push_back(dst);
    }

    vector<T> topological_sort()
    {
        unordered_map<T, int> in_degree;
        for (auto entry : edges)
        {
            for (auto neighbor : entry.second)
            {
                ++in_degree[neighbor];
            }
        }
    
        queue<T> q;
        for (auto node : nodes)
        {
            if (in_degree[node] == 0)
                q.push(node);
        }

        vector<T> result;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            result.push_back(node);

            if (edges.count(node) == 0)
                continue;

            for (auto neighbor : edges[node])
            {
                --in_degree[neighbor];
                if (in_degree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return result;
    }

    void display_graph()
    {
        cout << nodes.size() << " nodes, " << edges.size() << " edges: " << endl;
        for (auto item : edges)
        {
            cout << item.first << " -> ";
            for (auto neighbor : item.second)
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

private:
    unordered_map<T, vector<T>> edges;
    unordered_set<T> nodes;
};


int main()
{
    ifstream fin("./data/graph.in");
    ofstream fout("./data/sorted.out");

    int N, M; //N: number of nodes, M: number of edges
    fin >> N >> M;

    vector<int> v;
    for (int i=1; i <= N; ++i)
        v.push_back(i);

    graph<int> g(v.begin(), v.end());
    for (int i=0; i < M; ++i)
    {
        int src, dst;
        fin >> src >> dst;
        g.add_edge(src, dst);
    }
    //g.display_graph();

    cout << "topological order:\n";
    auto result = g.topological_sort();
    for (auto node : result)
    {
        fout << node << " ";
        cout << node << " ";
    }
    fout << endl;
    cout << endl;

    return 0;
}


