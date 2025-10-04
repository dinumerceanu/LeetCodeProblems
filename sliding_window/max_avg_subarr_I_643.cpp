#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int left = 0, right = 0;
    int sum = 0;
    double bestAvg = -1e9;

    while (right < nums.size()) {
        sum += nums[right];

        if (right - left + 1 == k) {
            bestAvg = max(bestAvg, (double)sum / k);
            sum -= nums[left];
            left++;
        }

        right++;
    }

    return bestAvg;
}

int main() {
    int k = 4;
    vector<int> nums = {1,12,-5,-6,50,3};

    cout << findMaxAverage(nums, k) << endl;

    return 0;
}
