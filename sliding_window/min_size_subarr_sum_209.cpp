#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    long long sum = 0;
    int bestLen = INT_MAX;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        while (sum >= target) {
            bestLen = min(bestLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    return bestLen == INT_MAX ? 0 : bestLen;
}

int main() {
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};

    cout << minSubArrayLen(target, nums) << endl;

    return 0;
}
