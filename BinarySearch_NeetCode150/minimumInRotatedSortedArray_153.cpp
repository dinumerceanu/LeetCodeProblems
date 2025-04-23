#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    nums.insert(nums.begin(), 1e9);
    nums.push_back(1e9);
    int left = 1, right = nums.size() - 2, m;
    while (left <= right) {
        m = (left + right) / 2;
        if (nums[m] < nums[m - 1] && nums[m] < nums[m + 1])
            return nums[m];
        if (nums[m] < nums[right])
            right = m - 1;
        else
            left = m + 1;
    }
    return -1;
}

int main() {
    vector<int> nums = {11, 13, 15, 17};
    cout<<findMin(nums)<<endl;

    return 0;
}