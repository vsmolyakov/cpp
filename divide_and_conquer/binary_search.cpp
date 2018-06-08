#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int bsearch(const vector<int> &arr, int l, int r, int q)
{
    while (l <= r)
    {
        int mid = l + (r-l)/2; 

        if (arr[mid] == q)
            return mid;

        if (q < arr[mid])
        {
           r = mid - 1;
        }
        else
        {
           l = mid + 1;
        }
    
    }
    return -1;
}

int main()
{
    int query = 10;
    int arr[] = {2, 4, 6, 8, 10, 12};
    int N = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr, arr + N);
   
    //sort input array
    sort(v.begin(), v.end());

    //std binary search
    if (binary_search(v.begin(), v.end(), query))
        cout << "std binary_search: found" << endl;
    else
        cout << "std binary_search: not found" << endl;

    int idx;
    idx = bsearch(v, 0, v.size(), query);
   
    if (idx != -1)
        cout << "custom binary_search: found at index " << idx << endl;
    else
        cout << "custom binary_search: not found" << endl;

    return 0;
}

