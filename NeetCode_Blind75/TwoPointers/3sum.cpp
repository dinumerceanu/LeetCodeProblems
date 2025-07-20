#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] > 0) {
                right--;
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                left++;
            } else {
                res.push_back({nums[i], nums[left], nums[right]});
                left++;
                while (nums[left] == nums[left - 1] && left < right) {
                    left++;
                }
            }
        }
    }

    return res;
}

int main() {
    ifstream fin("file.in");

    vector<int> nums;
    int x;

    while (fin >> x) {
        nums.push_back(x);
    }

    vector<vector<int>> res = threeSum(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
