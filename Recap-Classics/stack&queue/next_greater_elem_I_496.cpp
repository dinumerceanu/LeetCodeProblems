#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res(nums1.size(), -1);
    vector<int> stack;
    unordered_map<int, int> greater;
    
    for (int i = 0; i < nums2.size(); i++) {
        if (stack.empty()) {
            stack.push_back(nums2[i]);
        } else {
            while (!stack.empty() && stack.back() < nums2[i]) {
                greater[stack.back()] = nums2[i];
                stack.pop_back();
            }
            stack.push_back(nums2[i]);
        }
    }

    for (int i = 0; i < nums1.size(); i++) {
        if (greater.find(nums1[i]) != greater.end()) {
            res[i] = greater[nums1[i]];
        }
    }

    return res;
}

int main() {
    vector<int> nums1 = {2,4}, nums2 = {1,2,3,4};
    vector<int> res = nextGreaterElement(nums1, nums2);

    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
