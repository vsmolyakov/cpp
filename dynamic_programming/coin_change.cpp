#include <cstdio>
#include <cstring>
using namespace std;

int N=5, V, coin_value[5] = {50, 25, 10, 5, 1};
int memo[6][7500];  // max V is 7499

int ways(int type, int value)
{
    if (value == 0) return 1;
    if (value < 0 || type == N) return 0;
    if (memo[type][value] != -1) return memo[type][value];
    return memo[type][value] = ways(type + 1, value) + ways(type, value - coin_value[type]);
}

int main()
{
    memset(memo, -1, sizeof(memo));
    printf("enter total value (int [0, 7499]):"); scanf("%d", &V);
    printf("number of coins: ");
    int num_coins = ways(0, V);
    printf("%d\n", num_coins);

    return 0;
}
