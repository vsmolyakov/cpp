#include <vector>
#include <iostream>
using namespace std;

int cnt;
vector<int> subset;

void print_vec(vector<int> vec)
{
    for (int i=0; i < (int) vec.size(); ++i) {printf("%d ", vec[i]);}
}

void search(int k, int n)
{
    if (k == n)
    {
        //process subset
        printf("%d: ", cnt++); print_vec(subset); printf("\n");
    }
    else
    {
        search(k+1, n);
        subset.push_back(k);
        search(k+1, n);
        subset.pop_back();
    }
}

void bitseq(int n)
{
    for (int b = 0; b < (1 << n); ++b)
    {
        vector<int> subset;
        for (int i = 0; i < n; ++i)
        {
            if (b & (1<<i)){subset.push_back(i);}
        }
        
        //process subset
        printf("%d: ", cnt++); print_vec(subset); printf("\n");
    }
}

int main()
{
    int n = 4; //gen all subsets of [0..n]
    printf("all subsets of [0..%d]:\n", n);
    cnt = 0;
    search(0, n); //recursive

    //cnt = 0;
    //bitseq(n); //iterative

    return 0;
}


