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
            return m;
        if (nums[m] < nums[right])
            right = m - 1;
        else
            left = m + 1;
    }
    return -1;
}

int search(vector<int> nums, int target) {
    int index_min = findMin(nums);
    if (target == nums[1]) {
        return 0;
    }
    if (target == nums[nums.size() - 2]) {
        return nums.size() - 3;
    }
    if (target <= nums[index_min - 1] && target >= nums[1]) {
        int left = 1, right = index_min - 1, m;
        while (left <= right) {
            m = (left + right) / 2;
            if (target == nums[m])
                return m - 1;
            if (target < nums[m])
                right = m - 1;
            else
                left = m + 1;
        }
    }
    if (target <= nums[nums.size() - 2] && target >= nums[index_min]) {
        int left = index_min, right = nums.size() - 2, m;
        while (left <= right) {
            m = (left + right) / 2;
            if (target == nums[m])
                return m - 1;
            if (target < nums[m])
                right = m - 1;
            else
                left = m + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {1,3};
    int target = 2, index_min;
    cout<<search(nums, target)<<endl;

    return 0;
}