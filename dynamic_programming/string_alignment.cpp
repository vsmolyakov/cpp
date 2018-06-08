#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_LEN 20
char A[MAX_LEN] = "ACAATCC";
char B[MAX_LEN] = "AGCATGC";
int table[MAX_LEN][MAX_LEN]; //DP table

vector<char> needleman_wunsch(int table[MAX_LEN][MAX_LEN], int n, int m)
{
    //init DP table (bottom-up)
    //base case: insert/delete = -1 point
    for (int i = 1; i <= n; ++i){table[i][0] = -1*i;}
    for (int j = 1; j <= m; ++j){table[0][j] = -1*j;}

    //recursion
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            //match = 2 points, mismatch = -1 point
            table[i][j] = table[i-1][j-1] + (A[i-1] == B[j-1] ? 2 : -1);
            //insert / delete = - 1 point
            table[i][j] = max(table[i][j], table[i-1][j] - 1); //delete
            table[i][j] = max(table[i][j], table[i][j-1] - 1); //insert
        }
    }

    //backtrace
    int i = n, j = m;
    vector<char> result;
    while (i > 0 && j > 0)
    {
        if (A[i-1] == B[j-1])
        {
            result.push_back(A[i-1]);
            --i; --j;
        }
        else if (table[i-1][j] > table[i][j-1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int n = (int)strlen(A), m = (int)strlen(B);
    memset(table, 0, sizeof(table));

    printf("String Alignment (Needleman-Wunsch)\n");
    printf("1: %s\n", A); printf("2: %s\n", B);
    vector<char> result;
    result = needleman_wunsch(table, n, m);

    printf("DP table:\n");
    for (int i=0; i <= n; ++i)
    {
        for (int j=0; j <= m; ++j)
        {
            printf("%3d", table[i][j]);
        }
        printf("\n");
    }

    printf("Max alignment score: %d\n", table[n][m]);
    for (auto it = result.begin(); it != result.end(); ++it){cout << *it << " ";}
    printf("\n"); 

    return 0;
}
