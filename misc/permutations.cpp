#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void permute_recursive(vector<int>& nums, int start, vector<vector<int>>& result)
{
    //base case
    if (start >= (int) nums.size())
    {
        result.push_back(nums);
        return;
    }

    //recursion
    for (int i = start; i < (int) nums.size(); ++i)
    {
        swap(nums[start], nums[i]);
        permute_recursive(nums, start+1, result);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
   vector<vector<int>> result;
   permute_recursive(nums, 0, result);
   return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums); //O(n!)
    
    cout << "all possible permutations" << endl;
    for (int i = 0; i < (int) permutations.size(); ++i)
    {
        for (int j = 0; j < (int) permutations[0].size(); ++j)
        {
            cout << permutations[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
