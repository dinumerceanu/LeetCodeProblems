#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();

    if (n % groupSize != 0) {
        return false;
    }

    map<int,int> map;
    priority_queue<int> minHeap;

    for (int i = 0; i < n; i++) {
        map[hand[i]]++;
    }

    for (const auto& entry : map) {
        minHeap.push(-entry.first);
    }

    while (!minHeap.empty()) {
        int first_in_group = -minHeap.top();
        minHeap.pop();

        if (map[first_in_group] == 0) {
            continue;
        }

        map[first_in_group]--;
        
        if (map[first_in_group] == 0) {
            map.erase(first_in_group);
        } else {
            minHeap.push(-first_in_group);
        }

        for (int i = 1; i < groupSize; i++) {
            if (map[first_in_group + i] == 0) {
                return false;
            }

            map[first_in_group + i]--;

            if (map[first_in_group + i] == 0) {
                map.erase(first_in_group + i);
            }
        }
    }

    return true;
}

int main() {
    vector<int> hand = {1,1,2,2,3,3};
    int groupSize = 3;

    if (isNStraightHand(hand, groupSize)) {
        cout << "TRUE\n";
    } else {
        cout << "FALSE\n";
    }

    return 0;
}
