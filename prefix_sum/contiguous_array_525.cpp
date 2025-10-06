#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> map;
    map[0] = -1;
    int s = 0, maxLength = 0;

    for (int i = 0; i < nums.size(); i++) {
        s += (nums[i] == 1 ? 1 : -1);

        if (map.find(s) != map.end()) {
            maxLength = max(maxLength, i - map[s]);
        } else {
            map[s] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {0,1,1,1,1,1,0,0,0};

    cout << findMaxLength(nums) << endl;

    return 0;
}
