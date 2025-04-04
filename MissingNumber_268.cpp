#include <iostream>
#include <vector>

using namespace std;

vector<int> slice(vector<int>& v, int start, int end) {
    if (start < 0) start = 0;
    if (end > v.size()) end = v.size();
    if (start > end) return {};

    return vector<int>(v.begin() + start, v.begin() + end);
}

vector<int> merge(vector<int> a, vector<int> b) {
    int i = 0, j = 0;
    vector<int> aux;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            aux.push_back(a[i]);
            i++;
        } else if (a[i] > b[j]) {
            aux.push_back(b[j]);
            j++;
        } else {
            aux.push_back(a[i]);
            aux.push_back(b[j]);
            i++;
            j++;
        }
    }
    while (i < a.size()) {
        aux.push_back(a[i++]);
    }
    while (j < b.size()) {
        aux.push_back(b[j++]);
    }

    return aux;
}

vector<int> mergesort(vector<int> array) {
    if (array.size() <= 1) return array;

    int m = array.size() / 2;
    vector<int> left = mergesort(slice(array, 0, m));
    vector<int> right = mergesort(slice(array, m, array.size()));

    return merge(left, right);
}

int missingNumber(vector<int>& nums) {
    vector<int> sorted_nums = mergesort(nums);
    for (int i = 1; i < nums.size(); i++) {
        if (sorted_nums[i] - sorted_nums[i - 1] != 1) {
            return sorted_nums[i] - 1;
        }
    }
    if (sorted_nums[sorted_nums.size() - 1] != sorted_nums.size()) {
        return sorted_nums.size();
    } else {
        return 0;
    }
}

int main() {
    vector<int> array = {9,6,4,2,3,5,7,0,1};
    cout<<missingNumber(array)<<endl;

    return 0;
}
