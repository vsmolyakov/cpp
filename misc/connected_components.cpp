#include <vector>
#include <iostream>
using namespace std;


void DFS(vector<vector<char>>& grid, int i, int j, int num_rows, int num_cols)
{
    grid[i][j] = '0'; //reset current cell
        
    //recurse on 4-connected neighbors
    if (i > 0 && grid[i-1][j] == '1') 
    {
        DFS(grid, i-1, j, num_rows, num_cols);
    }
    if (i < num_rows - 1 && grid[i+1][j] == '1')
    {
        DFS(grid, i+1, j, num_rows, num_cols);
    }
    if (j > 0 && grid[i][j-1] == '1')
    {
        DFS(grid, i, j-1, num_rows, num_cols);
    }
    if (j < num_cols - 1 && grid[i][j+1] == '1')
    {
        DFS(grid, i, j+1, num_rows, num_cols);
    }
}

int numIslands(vector<vector<char>>& grid)
{
    int result = 0;
    if (grid.size() == 0 || grid[0].size() == 0) {return 0;}
    int num_rows = grid.size(); int num_cols = grid[0].size();
        
    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < num_cols; ++j)
        {
            if (grid[i][j] == '1')
            {
                result++;
                DFS(grid, i, j, num_rows, num_cols);
            }
        }
    }
    return result;        
}


int main()
{

    vector<vector<char>> grid = {{'1','1','0','0','0'},
                                 {'1','1','0','0','0'},
                                 {'0','0','1','0','0'},
                                 {'0','0','0','1','1'}};

    cout << "grid: " << endl;
    for (int i = 0; i < (int) grid.size(); ++i)
    {
        for (int j = 0; j < (int) grid[0].size(); ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    int num_components = numIslands(grid);
    cout << "number of connected components: " << num_components << endl;

    return 0;
}
