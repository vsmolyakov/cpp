#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> intersect (vector<int>& nums1, vector<int>& nums2)
{
    vector<int> result;
    unordered_map<int, int> hist;

    for (int item : nums1) {hist[item]++;}
    for (int item : nums2)
    {
        if (--hist[item] >= 0) {result.push_back(item);}
    }
    return result;
}

int main()
{
    vector<int> nums1 = {1,2,3,4,5,6,7};
    vector<int> nums2 = {4,5,6,7,8,9,10};

    cout << "nums1: " << endl;
    for (int i = 0; i < (int) nums1.size(); ++i){cout << nums1[i] << " ";}
    cout << endl;
    
    cout << "nums2: " << endl;
    for (int i = 0; i < (int) nums2.size(); ++i){cout << nums2[i] << " ";}
    cout << endl;

    cout << "intersection: " << endl;
    vector<int> intersection = intersect(nums1, nums2);
    for (int i = 0; i < (int) intersection.size(); ++i) {cout << intersection[i] << " ";}
    cout << endl;

    return 0;
}
