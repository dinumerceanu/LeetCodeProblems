#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, m;
    while (left <= right) {
        m = (left + right) / 2;
        if (nums[m] == target)
            return m;
        if (nums[m] < target)
            left = m + 1;
        else
            right = m - 1;
    }
    return -1;
}

int main() {
    vector<int> array = {-1,0,3,5,9,12};
    cout<<search(array, 3);

    return 0;
}
