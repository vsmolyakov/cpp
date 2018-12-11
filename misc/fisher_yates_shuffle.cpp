#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

void shuffle(int arr[], int n)
{
    srand (time(NULL)); //init random seed

    for (int i = n-1; i > 0; --i)
    {
        //pick a random index from 0 to i
        int j = rand() % (i+1);

        // swap arr[i] with element at random index
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Fisher-Yates shuffle: " << endl;
    shuffle(arr, n);
    for (int i = 0; i < n; ++i){cout << arr[i] << " ";}
    cout << endl;

    return 0;
}

