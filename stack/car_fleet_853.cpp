#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> pairs;
    vector<float> stack;

    for (int i = 0; i < position.size(); i++) {
        pairs.push_back({position[i], speed[i]});
    }

    sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.first > b.first;});

    for (int i = 0; i < pairs.size(); i++) {
        float iterations = ((float)(target - pairs[i].first)) / pairs[i].second;

        if (stack.empty()) {
            stack.push_back(iterations);
        } else {
            if (iterations > stack.back()) {
                stack.push_back(iterations);
            }
        }
    }

    return stack.size();
}

int main() {
    int target = 10;
    vector<int> position = {6, 8};
    vector<int> speed = {3, 2};

    cout << carFleet(target, position, speed) << endl;

    return 0;
}
