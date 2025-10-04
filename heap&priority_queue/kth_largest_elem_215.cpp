#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> heap;

    for (int i = 0; i < nums.size(); i++) {
        heap.push(nums[i]);
    }

    for (int i = 0; i < k - 1; i++) {
        heap.pop();
    }

    return heap.top();
}

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;

    cout << findKthLargest(nums, k) << endl;

    return 0;
}
