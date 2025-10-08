#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), res = 1;
    vector<int> LIS(n, 1);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] < nums[j]) {
                LIS[i] = max(LIS[i], 1 + LIS[j]);
                res = max(res, LIS[i]);
            }
        }
    }

    return res;
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};

    cout << lengthOfLIS(nums) << endl;

    return 0;
}
