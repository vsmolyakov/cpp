#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

//row[8]: row # for each queen
//TC: traceback counter
//(a, b): 1st queen placement at (r=a, c=b)
int row[8], TC, a, b, line_counter;

bool place(int r, int c)
{
    // check previously placed queens
    for (int prev = 0; prev < c; prev++)
    {
        // check if same row or same diagonal
        if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
            return false;
    }
    return true;
}

void backtrack(int c)
{
    // candidate solution; (a, b) has 1 initial queen
    if (c == 8 && row[b] == a)
    {
        printf("%2d    %d", ++line_counter, row[0] + 1);
        for (int j=1; j < 8; j++) {printf(" %d", row[j] + 1);}
        printf("\n");
    }

    //try all possible rows
    for (int r = 0; r < 8; r++)
    {
        if (place(r, c))
        {
            row[c] = r; // place a queen at this col and row
            backtrack(c + 1); //increment col and recurse
        }
    }
}

int main() 
{
    scanf("%d", &TC);
    while (TC--)
    {
        scanf("%d %d", &a, &b); a--; b--; //0-based indexing
        memset(row, 0, sizeof(row)); line_counter = 0;
        printf("SOLN       COLUMN\n");
        printf(" #    1 2 3 4 5 6 7 8\n\n");
        backtrack(0); //generate all possible 8! candidate solutions
        if (TC) printf("\n");
    }

    return 0;
}
