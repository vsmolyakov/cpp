#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

void bucket_sort(float arr[], int n)
{
    //linear time for uniformly distributed floats
    //assumes arr[i] ~ Unif[0, 1]

    //create n empty buckets
    vector<float> b[n];

    //put array elements in different buckets
    for (int i = 0; i < n; ++i)
    {
        int bi = n * arr[i]; //bucket index
        b[bi].push_back(arr[i]);
    }

    //sort individual buckets
    for (int i = 0; i < n; ++i)
        sort(b[i].begin(), b[i].end());

    //concatenate all buckets into array
    int index = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < (int) b[i].size(); ++j)
            arr[index++] = b[i][j];

}

int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "bucket sort: " << endl;
    bucket_sort(arr, n);
    for (int i = 0; i < n; ++i) {cout << arr[i] << " ";}
    cout << endl;

    return 0;
}
