#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int nums_xor_ed = 0;
    int all_nums_xor_ed = 0;

    for (int i = 0; i <= n; i++) {
        if (i < n) {
            nums_xor_ed ^= nums[i];
        }

        nums_xor_ed ^= i;
    }

    return nums_xor_ed ^ all_nums_xor_ed;
}

int main() {
    vector<int> nums = {1,0,3};

    cout << missingNumber(nums) << endl;

    return 0;
}
