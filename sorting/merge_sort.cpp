#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //create temp arrays
    int L[n1], R[n2];

    //copy data to temp arrays
    for (i=0; i < n1; ++i) {L[i] = arr[l+i];}
    for (j=0; j < n2; ++j) {R[j] = arr[m+j+1];}

    //merge temp arrays into back into arr[1..r]
    i = 0; //init index of first sub-array
    j = 0; //init index of second sub-array
    k = l; //init index of merged sub-array

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //copy remaining elements of L if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    //copy remaining elements of R if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        //same as (l+r)/2 but avoids
        //overflow for large l and r
        int m = l + (r-l)/2;

        //divide array into two halves
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);

        //merge sorted sub-arrays
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    printf("merge sort:\n");
    merge_sort(arr, 0, arr_size-1);
   
    for (int i=0; i < arr_size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}





