#include <algorithm>
#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r-1; ++j)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int kth_smallest(int arr[], int l, int r, int k)
{
    if (k < 0 || k > r-l+1) {return -1;}

    //partition the array (similar to quicksort)
    int index = partition(arr, l, r);

    //if position same as k return rank-k element
    if (index - l == k - 1)
        return arr[index];

    //if rank-k element is less, look in left sub-array
    if (index - l > k - 1)
        return kth_smallest(arr, l, index - 1, k);
    else //look in right sub-array
        return kth_smallest(arr, index + 1, r, k - index + l - 1);

}

int main()
{
    int arr[] = {10, 4, 5, 8, 6, 11, 26}; //assumes distince elements
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3; //rank

    cout << "input array: " << endl;
    for (int i = 0; i < n; ++i) {cout << arr[i] << " ";}
    cout << endl;

    //O(n) time with O(n^2) worst case
    int result = kth_smallest(arr, 0, n-1, k); 
    printf("kth smallest element (k=%d) is: %d \n", k, result);

    return 0;
}
