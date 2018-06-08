#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

template <class type_t>
type_t longest_common_substring(const type_t& A, const type_t& B)
{
    //best[i][j] = int length of longest common substring 
    //             between A[0,i] and B[0,j]

    vector<vector<int>> best(A.size()+1, vector<int>(B.size()+1));

    //recursion:
    for (int i=1; i<A.size(); ++i)
    {
        for (int j=1; j<B.size(); ++j)
        {
            if (A[i-1] == B[j-1])
            {
                best[i][j] = best[i-1][j-1] + 1;
            }
            else 
            {
                best[i][j] = max(best[i-1][j], best[i][j-1]);
            }
        }
    }

    type_t result;

    //backtrace
    int i = A.size(), j = B.size();
    while (i > 0 && j > 0)
    {
        if (A[i-1] == B[j-1])
        {
            result.push_back(A[i-1]);
            --i; --j;
        }
        else if (best[i-1][j] > best[i][j-1])
            --i;
        else
            --j;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    ifstream fin("./data/lcs.in");
    ofstream fout("./data/lcs.out");

    int N, M;
    fin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        fin >> A[i];

    vector<int> B(M);
    for (int i = 0; i < M; ++i)
        fin >> B[i];

    vector<int> result;
    result = longest_common_substring(A, B);

    fout << result.size() << "\n";
    cout << result.size() << "\n";
    for (auto it = result.begin(); it < result.end(); ++it)
    {
        fout << *it << " ";
        cout << *it << " ";
    }
    fout << "\n";
    cout << "\n";

    return 0;
}



