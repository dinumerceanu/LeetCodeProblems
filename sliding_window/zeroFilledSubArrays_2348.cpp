#include <iostream>
#include <vector>

using namespace std;

long long zeroFilledSubarray(vector<int>& nums) {
    long long count = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            int j;
            for (j = i; j < nums.size(); j++) {
                if (nums[j] != 0) {
                    break;
                }
            }

            long long seqLen = j - i;
            count += (seqLen * (seqLen + 1)) / 2;
            i = j;
        }
    }

    return count;
}

int main() {
    vector<int> nums = {1,3,0,0,2,0,0,4};

    cout << zeroFilledSubarray(nums) << endl;

    return 0;
}
