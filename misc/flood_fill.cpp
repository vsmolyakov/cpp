#include <iostream>
using namespace std;

#define M 8
#define N 8

int component_count = 0; //global

//recursive function to replace prev color with new color
void flood_fill_util(int screen[][N], int x, int y, int prevC, int newC)
{
    // base case
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != prevC)
        return;

    // replace the color at (x, y)
    screen[x][y] = newC;
    component_count++;

    flood_fill_util(screen, x+1, y, prevC, newC); //south neighbor
    flood_fill_util(screen, x-1, y, prevC, newC); //north neighbor
    flood_fill_util(screen, x, y+1, prevC, newC); //east neighbor
    flood_fill_util(screen, x, y-1, prevC, newC); //west neighbor

}

void flood_fill(int screen[][N], int x, int y, int newC)
{
    int prevC = screen[x][y];
    flood_fill_util(screen, x, y, prevC, newC);
}

int main()
{
    int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1, 0, 1, 1},
                        {1, 2, 2, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 2, 2, 0},
                        {1, 1, 1, 1, 1, 2, 1, 1},
                        {1, 1, 1, 1, 1, 2, 2, 1},
                       };

    int x = 4, y = 4, newC = 3;
    flood_fill(screen, x, y, newC);

    cout << "new screen after flood fill:" << endl;
    for (int i=0; i<M; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
    cout << "number of elements in the connected comonent: " << component_count << endl;

    return 0;
}
