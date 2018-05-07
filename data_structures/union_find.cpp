#include <iostream>
#include <vector>
using namespace std;

class union_find
{
public:
    union_find(int N)
    {
        num_sets = N; set_size.assign(N,1);
        rank.assign(N,0); p.assign(N,0);
        for (int i=0; i < N; i++) {p[i] = i;}
    }

    int find_set(int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}
    bool is_same_set(int i, int j) {return find_set(i) == find_set(j);}
    void union_set(int i, int j)
    {
        if (!is_same_set(i, j))
        {
            num_sets--;
            int x = find_set(i);
            int y = find_set(j);

            //rank heuristic is used to keep the tree height small
            if (rank[x] > rank[y])
            {
                p[y] = x; set_size[x] += set_size[y];
            }
            else
            {
                p[x] = y; set_size[y] += set_size[x];
                if (rank[x] == rank[y]) {rank[y]++;}
            }
        }
    }
    int num_disjoint_sets() {return num_sets;}
    int size_of_set(int i) {return set_size[find_set(i)];}

private:
    int num_sets;
    vector<int> p, rank, set_size;
};

int main()
{
    union_find UF(5);
    cout << "number of disjoint sets: " << UF.num_disjoint_sets() << endl;
    
    UF.union_set(0,1);
    cout << "number of disjoint sets: " << UF.num_disjoint_sets() << endl;
    UF.union_set(2,3);
    cout << "number of disjoint sets: " << UF.num_disjoint_sets() << endl;
    UF.union_set(4,3);
    cout << "number of disjoint sets: " << UF.num_disjoint_sets() << endl;

    cout << "is same set (0, 3): " << UF.is_same_set(0, 3) << endl;
    cout << "is same set (4, 3): " << UF.is_same_set(4, 3) << endl;

    for (int i=0; i < 5; i++)
    {
        printf("find_set(%d) = %d, size_of_set(%d) = %d\n", i, UF.find_set(i), i, UF.size_of_set(i));
    }

    UF.union_set(0, 3);
    cout << "number of disjoint sets: " << UF.num_disjoint_sets() << endl;

    for (int i=0; i < 5; i++)
    {
        printf("find_set(%d) = %d, size_of_set(%d) = %d\n", i, UF.find_set(i), i, UF.size_of_set(i));
    }

    return 0;
}








