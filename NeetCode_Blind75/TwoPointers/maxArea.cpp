#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1, max_area = 0, area;

    while (left < right) {
        area = (right - left) * min(height[left], height[right]);
        if (area > max_area) {
            max_area = area;
        }
        if (height[left] > height[right]) {
            right--;
        } else {
            left++;
        }
    }

    return max_area;
}

int main() {
    ifstream fin("file.in");

    vector<int> height;
    int x;

    while (fin >> x) {
        height.push_back(x);
    }

    int res = maxArea(height);
    cout << res << endl;

    return 0;
}
