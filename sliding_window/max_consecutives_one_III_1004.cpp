#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int left = 0, right = 0;
    unordered_map<int, int> freq;
    freq.insert({0, 0});
    freq.insert({1, 0});
    int res = 0;

    while (right < nums.size()) {
        freq[nums[right]]++;

        if (freq[0] <= k) {
            res = right - left + 1;
        } else {
            freq[nums[left]]--;
            left++;
        }

        right++;
    }

    return res;
}

int main() {
    int k = 2;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};

    cout << longestOnes(nums, k) << endl;

    return 0;
}
