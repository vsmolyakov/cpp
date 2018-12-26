#include <iostream>
#include <vector>
using namespace std;

int coin_value[5] = {50, 25, 10, 5, 1};
int N = sizeof(coin_value)/sizeof(coin_value[0]);

vector<int> coin_change(int value)
{
    vector<int> result;
    for (int i = 0; i < N; ++i)
    {
        while (value >= coin_value[i])
        {
            value -= coin_value[i];
            result.push_back(coin_value[i]);
        }
    }

    return result;
}

int main()
{
    int total = 93;
    cout << "Minimum coin change for " << total << " is:" << endl;
    vector<int> change = coin_change(total);
    for (int i = 0; i < (int) change.size(); ++i) {cout << change[i] << " ";}
    cout << endl;

    return 0;
}
