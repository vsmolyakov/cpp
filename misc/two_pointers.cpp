#include <vector>
#include <iostream>
using namespace std;

int remove_element(vector<int>& nums, int val)
{
    //k: slow moving pointer, i: fast moving pointer
    int k = 0;
    for (int i = 0; i < (int) nums.size(); ++i)
    {
        if (nums[i] != val)
        {
            nums[k] = nums[i];
            ++k;
        }
    }

    return k; //new vector size
}

int main()
{
    int item = 5;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    int k = remove_element(nums, item);

    cout << "vector with element " << item << " removed:" << endl;
    for (int i = 0; i < k; ++i) {cout << nums[i] << " ";}
    cout << endl;

    return 0;
}
