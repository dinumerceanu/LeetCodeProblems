#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> pre_product(nums.size());
    vector<int> post_product(nums.size());
    int prod = 1;

    for (int i = 0; i < nums.size(); i++) {
        prod = prod * nums[i];
        pre_product[i] = prod;
    }

    prod = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        prod = prod * nums[i];
        post_product[i] = prod;
    }

    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) {
            res.push_back(post_product[1]);
        }
        else if (i == nums.size() - 1) {
            res.push_back(pre_product[nums.size() - 2]);
        } else {
            res.push_back(pre_product[i - 1] * post_product[i + 1]);
        }
    }

    return res;
}

int main() {
    ifstream fin("file.in");
    
    int x;
    vector<int> nums;

    while (fin >> x) {
        nums.push_back(x);
    }

    vector<int> res = productExceptSelf(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}