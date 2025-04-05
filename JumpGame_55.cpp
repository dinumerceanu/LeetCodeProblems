#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int lenght = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > lenght) {
            return false;
        }
        lenght = max(lenght, i + nums[i]);
        if (lenght >= nums.size() - 1) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> array = {2,3,1,1,4};
    cout<<canJump(array);

    return 0;
}