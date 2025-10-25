#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int l = 0, r = 0, currSum = 0, bestSum = -1e9;
    
    while (r < nums.size()) {
        if (currSum < 0 && nums[r] > currSum) {
            currSum = nums[r];
            r++;
            l = r;
        } else {
            currSum += nums[r];
            r++;
        }

        if (currSum > bestSum) {
            bestSum = currSum;
        }
    }

    return bestSum;
}

int main() {
    vector<int> nums = {5,4,-1,7,8};

    cout << maxSubArray(nums) << endl;

    return 0;
}
