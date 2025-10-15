#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int end = nums.size() - 1;

    for (int i = nums.size() - 1; i >= 0; i--) {
        if (i + nums[i] >= end) {
            end = i;
        }
    }

    if (end == 0) {
        return true;
    }
    return false;
}

int main() {
    vector<int> nums = {2,3,1,1,4};

    cout << canJump(nums) << endl;

    return 0;
}
