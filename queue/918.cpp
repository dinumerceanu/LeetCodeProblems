#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int sum = 0, curr_max = 0, curr_min = 0, best_max = nums[0], best_min = nums[0];

    for (int num : nums) {
        curr_max = max(num, num + curr_max);
        best_max = max(curr_max, best_max);

        curr_min = min(num, num + curr_min);
        best_min = min(curr_min, best_min);

        sum += num;
    }

    if (best_max < 0) {
        return best_max;
    }

    return max(best_max, sum - best_min);
}

int main() {
    vector<int> nums = {-3,-2,-3};

    cout << maxSubarraySumCircular(nums) << endl;

    return 0;
}
