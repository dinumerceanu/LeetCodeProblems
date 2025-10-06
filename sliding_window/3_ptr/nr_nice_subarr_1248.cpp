#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int res = 0, odd = 0, left = 0, left_far = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] % 2 == 1) {
            odd++;
        }

        while (odd > k) {
            if (nums[left] % 2 == 1) {
                odd--;
            }

            left++;
            left_far = left;
        }

        if (odd == k) {
            while (nums[left_far] % 2 == 0) {
                left_far++;
            }

            res += (left_far - left) + 1;
        }
    }

    return res;
}

int main() {
    vector<int> nums = {1,1,2,1,1};
    int k = 3;

    cout << numberOfSubarrays(nums, k) << endl;

    return 0;
}
