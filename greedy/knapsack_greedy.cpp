#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int value, weight;
    Item(int value, int weight) : value(value), weight(weight) {}
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double) a.value / a.weight;
    double r2 = (double) b.value / b.weight;
    return r1 > r2;
}

double fractional_knapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    for (int i = 0; i < n; ++i)
    {
        double ratio = (double) arr[i].value / arr[i].weight;
        printf("(%3d, %3d) : %2.4f \n", arr[i].value, arr[i].weight, ratio);
    } 

    int cur_weight = 0;
    double tot_value = 0.0;

    for (int i=0; i < n; ++i)
    {
        if (cur_weight + arr[i].weight <= W)
        {
            cur_weight += arr[i].weight;
            tot_value  += arr[i].value;
        }
        else
        {
            //add a fraction of the next item
            int rem_weight = W - cur_weight;
            tot_value += arr[i].value * ((double) rem_weight / arr[i].weight);
            break;
        }
    }
    return tot_value;
}

int main()
{
    int W = 50; // total knapsack weight
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; // (value, weight)

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "greedy fractional knapsack" << endl;
    cout << "maximum value: " << fractional_knapsack(W, arr, n) << endl;

    return 0;
}
