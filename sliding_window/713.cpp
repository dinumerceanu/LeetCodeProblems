#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) {
        return 0;
    }

    int count = 0, l = 0, prod = 1;

    for (int r = 0; r < nums.size(); r++) {
        prod *= nums[r];

        while (prod >= k) {
            prod /= nums[l];
            l++;
        }

        count += r - l + 1;
    }

    return count;
}

int main() {
    vector<int> nums = {10,5,2,6};
    int k = 100;

    cout << numSubarrayProductLessThanK(nums, k) << endl;

    return 0;
}
