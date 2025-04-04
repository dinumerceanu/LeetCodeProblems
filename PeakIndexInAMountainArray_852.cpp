#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int left = 0, right = arr.size() - 1, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    vector<int> array = {0, 1, 12, 9, 3, 2};
    cout<<peakIndexInMountainArray(array);

    return 0;
}