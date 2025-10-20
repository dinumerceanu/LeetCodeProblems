#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    int l = 0, r = numbers.size() - 1;

    while (l < r) {
        if (numbers[l] + numbers[r] == target) {
            res.push_back(l + 1);
            res.push_back(r + 1);
            break;
        } else if (numbers[l] + numbers[r] < target) {
            l++;
        } else {
            r--;
        }
    }

    return res;
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(numbers, target);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
