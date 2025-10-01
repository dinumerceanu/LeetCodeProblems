#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }

    return res;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> res = maxSlidingWindow(nums, k);
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
