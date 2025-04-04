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
        if (a[i] > b[j]) {
            aux.push_back(a[i]);
            i++;
        } else if (a[i] < b[j]) {
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

int findKthLargest(vector<int> nums, int k) {
    vector<int> sorted = mergesort(nums);
    return sorted[k - 1];
}

int main() {
    vector<int> array = {3,2,3,1,2,4,5,5,6};
    vector<int> sorted_array = mergesort(array);
    cout<<findKthLargest(array, 4)<<endl;

    return 0;
}
