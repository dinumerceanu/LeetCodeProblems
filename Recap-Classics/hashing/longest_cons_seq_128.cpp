#include <iostream>
#include <vector>
#include <map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.size() < 2) {
        return nums.size();
    }

    map<int, int> freq;
    int res = 1;

    for (int i = 0; i < nums.size(); i++) {
        freq[nums[i]] += 1;
    }

    auto it = freq.begin();
    int prev = it->first;
    it++;
    int length = 1;
    for (; it != freq.end(); it++) {
        if (it->first == prev + 1) {
            length++;
        } else {
            length = 1;
        }
        if (length > res) {
            res = length;
        }
        prev = it->first;
    }

    return res;
}

int main() {
    vector<int> nums = {0,0};

    cout << longestConsecutive(nums) << endl;

    return 0;
}
