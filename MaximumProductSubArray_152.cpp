#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    int maxProd = nums[0], currMax = nums[0], currMin = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(currMax, currMin);
        currMax = max(nums[i], currMax * nums[i]);
        currMin = min(nums[i], currMin * nums[i]);
        maxProd = max(maxProd, currMax);
    }
    return maxProd;
}

int main() {
    vector<int> nums = {-2, 3, -4};
    cout<<maxProduct(nums);

    return 0;
}