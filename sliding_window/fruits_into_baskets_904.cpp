#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    int l = 0, r = 0, maxWindow = 0;

    unordered_map<int, int> freq;

    while (r < n) {
        freq[fruits[r]]++;

        while (freq.size() > 2) {
            freq[fruits[l]]--;

            if (freq[fruits[l]] == 0) {
                freq.erase(fruits[l]);
            }

            l++;
        }

        maxWindow = max(maxWindow, r - l + 1);
        r++;
    }

    return maxWindow;
}

int main() {
    vector<int> fruits = {1,0,3,4,3};

    cout << totalFruit(fruits) << endl;

    return 0;
}
