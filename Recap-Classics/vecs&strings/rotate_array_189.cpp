#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    vector<int> aux;
    k = k % nums.size();

    for (int i = nums.size() - k; i < nums.size(); i++) {
        aux.push_back(nums[i]);
    }

    for (int i = 0; i < nums.size() - k; i++) {
        aux.push_back(nums[i]);
    }

    for (int i = 0; i < nums.size(); i++) {
        nums[i] = aux[i];
    }
}

void rotate2(vector<int>& nums, int k) {
    k = k % nums.size();

    for (int i = 0; i < nums.size() / 2; i++) {
        swap(nums[i], nums[nums.size() - i - 1]);
    }

    for (int i = 0; i < k / 2; i++) {
        swap(nums[i], nums[k - i - 1]);
    }

    for (int i = k; i < k + (nums.size() - k) / 2; i++) {
        swap(nums[i], nums[nums.size() - 1 - (i - k)]);
    }
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate2(nums, 3);

    for (int num : nums) {
        printf("%d ", num);
    }
    printf("\n");

    return 0;
}
