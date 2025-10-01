#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;
    
    while (left < right) {
        int currentArea = (right - left) * min(height[right], height[left]);
        if (maxArea < currentArea) {
            maxArea = currentArea;
        }
        if (height[left] > height[right]) {
            right--;
        } else {
            left++;
        }
    }

    return maxArea;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;

    return 0;
}
