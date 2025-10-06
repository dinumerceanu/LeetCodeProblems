#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            sum.push_back(s);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return sum[right];
        }

        return sum[right] - sum[left - 1];
    }

private:
    vector<int> sum;
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;

    return 0;
}
