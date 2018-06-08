#include <iostream>
#include <cstring>
using namespace std;

#define V 8
int memo[V][V]; //DP table

int min(int a, int b) {return (a < b) ? a : b;}

void print_table(int memo[V][V])
{
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            printf(" %2d", memo[i][j]);
        }
        printf("\n");
    }
}

int binomial_coeffs1(int n, int k)
{
    // top-down DP
    if (k == 0 || k == n) return 1;
    if (memo[n][k] != -1) return memo[n][k];
    return memo[n][k] = binomial_coeffs1(n-1, k-1) + binomial_coeffs1(n-1, k);
}

int binomial_coeffs2(int n, int k)
{
    // bottom-up DP
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= min(i, k); ++j)
        {
            if (j == 0 || j == i)
            {
                memo[i][j] = 1;
            }
            else
            {
                memo[i][j] = memo[i-1][j-1] + memo[i-1][j]; 
            }
        }
    }
    return memo[n][k];
}


int main()
{
    int n = 5, k = 2;
    
    printf("Top-down DP:\n");
    memset(memo, -1, sizeof(memo));
    int nCk1 = binomial_coeffs1(n, k);
    print_table(memo);
    printf("C(n=%d, k=%d): %d\n", n, k, nCk1);

    printf("Bottom-up DP:\n");
    memset(memo, -1, sizeof(memo));
    int nCk2 = binomial_coeffs2(n, k);
    print_table(memo);
    printf("C(n=%d, k=%d): %d\n", n, k, nCk2);

    return 0;
}

