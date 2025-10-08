#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxProd = nums[0];
    int curMax = nums[0];
    int curMin = nums[0];

    for (int i = 1; i < n; i++) {
        int temp = curMax;

        curMax = max(nums[i], max(nums[i] * curMax, nums[i] * curMin));
        curMin = min(nums[i], min(nums[i] * temp, nums[i] * curMin));

        maxProd = max(maxProd, curMax);
    }

    return maxProd;
}

int main() {
    vector<int> nums = {-2, 0, -1};

    cout << maxProduct(nums) << endl;

    return 0;
}
