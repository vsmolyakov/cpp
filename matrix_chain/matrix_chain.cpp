#include <iostream>
#include <climits>
using namespace std;

#define MAX 10

int lookup[MAX][MAX]; //look-up table for storing solutions to already computed sub-problems

int matrix_chain_mult(int dims[], int i, int j)
{
    if (i+1 >= j) {return 0;}

    int min = INT_MAX;

    if (lookup[i][j] == 0)
    {
        //consider all possible matrix sub-groups
        for (int k=i+1; k<=j-1; ++k)
        {
            int cost = matrix_chain_mult(dims, i, k);
            cost += matrix_chain_mult(dims, k, j);
            cost += dims[i] * dims[k] * dims[j];

            if (cost < min) {min = cost;}
        }
    }
    lookup[i][j] = min;
    return lookup[i][j];
}

int main()
{
    //matrix M[i] has dimension dims[i-1] x dims[i] for i=1..n
    //input is 10 x 30 matrix, 30 x 5 matrix, 5 x 60 matrix
    int dims[] = {10, 30, 5, 60};
    int n = sizeof(dims) / sizeof(dims[0]);

    cout << "minimum cost: " << matrix_chain_mult(dims, 0, n-1) << endl;

    return 0;
}
