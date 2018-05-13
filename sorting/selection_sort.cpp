#include <iostream>
#include <algorithm>
using namespace std;

void selection_sort(int arr[], int n)
{
    int i, j, min_idx;

    // move boundary of unsorted sub-array
    for (i=0; i < n-1; ++i)
    {
        //find min element in unsorted array
        min_idx = i;
        for(j = i+1; j < n; ++j)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        //swap found min element with the boundary element
        swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n);

    printf("selection sort:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
