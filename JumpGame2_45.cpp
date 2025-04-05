#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    int res = 0, left = 0, right = 0, max_dist;
    while (right < nums.size() - 1) {
        max_dist = 0;
        for (int i = left; i <= right; i++) {
            max_dist = max(max_dist, i + nums[i]);
        }
        left = right + 1;
        right = max_dist;
        res += 1;
    }
    return res;
}

int main() {
    vector<int> array = {2,3,1,1,4};
    cout<<jump(array);

    return 0;
}
