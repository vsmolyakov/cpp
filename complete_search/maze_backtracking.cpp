#include <iostream>
#include <cstring>
using namespace std;

#define N 4

bool isValidCell(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;
    return true;
}

void countPaths(int maze[N][N], int x, int y, int visited[N][N], int& count)
{
    //if destination is found, 
    //increment the path count
    if (x == N-1 && y == N-1)
    {
        count++;
        return;
    }

    //mark current cell as visited
    visited[x][y] = 1;

    //if current cell is a valid and open cell
    if (isValidCell(x, y) && maze[x][y])
    {
        //go down (x, y) -> (x+1, y)
        if (x+1 < N && !visited[x+1][y])
            countPaths(maze, x+1, y, visited, count);
        
        //go up (x, y) -> (x-1, y)
        if (x-1 >= 0 && !visited[x-1][y])
            countPaths(maze, x-1, y, visited, count);

        //go right (x, y) -> (x, y+1)
        if (y+1 < N && !visited[x][y+1])
            countPaths(maze, x, y+1, visited, count);

        //go left (x, y) -> (x, y-1)
        if (y-1 >= 0 && !visited[x][y-1])
            countPaths(maze, x, y-1, visited, count);
    
    }

    //backtrack from current cell and remove it from current path
    visited[x][y] = 0;

}

int main()
{
    int maze[N][N] = {{1, 1, 1, 1},
                      {1, 1, 0, 1},
                      {0, 1, 0, 1},
                      {1, 1, 1, 1}};

    int count = 0; //number of unique paths from src to dst

    int visited[N][N];
    memset(visited, 0, sizeof(visited));

    countPaths(maze, 0, 0, visited, count);

    cout << "total number of unique paths: " << count;
    cout << endl;

    return 0;
}





