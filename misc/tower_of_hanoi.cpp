#include <iostream>
using namespace std;

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    tower_of_hanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n = 4;
    tower_of_hanoi(n, 'A', 'C', 'B');
    printf("\n");
    return 0;
}
