#include <vector>
#include <climits>
#include <iostream>
using namespace std;

//O(n) Kadane's Algorithm (positive and negative values)
int max_subarray_sum(const vector<int> & vec, const int N)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    int idx_start = 0, idx_end = 0, idx_temp = 0;

    for (int i=0; i < N; ++i)
    {
       max_ending_here = max_ending_here + vec[i];
       if (max_ending_here > max_so_far) 
       {
           max_so_far = max_ending_here;
           idx_start = idx_temp;
           idx_end = i;
       } 
       if (max_ending_here < 0) {max_ending_here = 0; idx_temp = i + 1;}
    }
    cout << "idx start: " << idx_start << ", " << "idx end: " << idx_end << endl;

    return max_so_far;
}

//O(n) dynamic programming (handles the case of all negative values)
int max_subarray_sum_dp(const vector<int> & vec, const int N)
{
    int max_so_far = vec[0];
    int curr_max = vec[0];

    for (int i=0; i < N; ++i)
    {
        curr_max = max(vec[i], curr_max + vec[i]);
        max_so_far = max(max_so_far, curr_max);
    }

    return max_so_far;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int N = sizeof(arr)/sizeof(arr[0]);
    
    vector<int> vec (arr, arr+N);
    for (auto item : vec){cout << item << " ";}
    cout << endl;

    int sum_kadane = 0;
    sum_kadane = max_subarray_sum(vec, N);

    int sum_dp = 0;
    sum_dp = max_subarray_sum_dp(vec, N);

    cout << "max subarray sum (Kadane): " << sum_kadane << endl;
    cout << "max subarray sum (DP): " << sum_dp << endl;

    return 0;
}
