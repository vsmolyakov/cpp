#include <vector>
#include <iostream>
using namespace std;

vector<int> spiral_order(vector<vector<int>>& matrix)
{
    if (matrix.empty()) {return {};}
    int m = matrix.size(), n = matrix[0].size();

    vector<int> spiral(m * n);
    int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
    while (true)
    {
        //up
        for (int col = l; col <= r; col++) {spiral[k++] = matrix[u][col];}
        if (++u > d) break;
        //right
        for (int row = u; row <= d; row++) {spiral[k++] = matrix[row][r];}
        if (--r < l) break;
        //down
        for (int col = r; col >= l; col--) {spiral[k++] = matrix[d][col];}
        if (--d < u) break;
        //left
        for (int row = d; row >= u; row--) {spiral[k++] = matrix[row][l];}
        if (++l > r) break;
    }
    return spiral;
}

int main()
{
    int m = 3, n = 3;
    vector<vector<int>> matrix;

    cout << "input matrix: " << endl;
    for (int i = 0; i < m; ++i)
    {
        vector<int> row;
        for (int j = 0; j < n; ++j)
        {
            row.push_back(i*n + j);
            cout << i*n + j << " ";
        }
        matrix.push_back(row);
        cout << endl;
    }
    cout << endl;

    cout << "matrix in spiral order: " << endl;
    vector<int> spiral;
    spiral = spiral_order(matrix);

    for (int i = 0; i < (int) spiral.size(); ++i) {cout << spiral[i] << " ";}
    cout << endl;

    return 0;
}



