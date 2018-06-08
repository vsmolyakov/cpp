#include <iostream>
using namespace std;

int max_sum(int arr[], int n, int k)
{
    //returns max sum in subarray of size k
    if (n < k) {cout << "Error: n < k\n"; return -1;}

    //compute sum of the first window
    int max_sum = 0;
    for (int i = 0; i < k; ++i) {max_sum += arr[i];}

    //compute sum of remaining windows by removing
    //first element and adding last eleement to curr window
    int window_sum = max_sum;
    for (int i = k; i < n; ++i)
    {
        window_sum += arr[i] - arr[i-k];
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

int main()
{
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Max window sum: %d\n", max_sum(arr, n, k));

    return 0;
}
