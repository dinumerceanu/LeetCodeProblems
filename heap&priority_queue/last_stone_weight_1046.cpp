#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxHeap;
    
    for (int i = 0; i < stones.size(); i++) {
        maxHeap.push(stones[i]);
    }

    while (maxHeap.size() > 1) {
        int x = maxHeap.top();
        maxHeap.pop();
        int y = maxHeap.top();
        maxHeap.pop();

        if (x != y) {
            maxHeap.push(x - y);
        }
    }

    if (maxHeap.empty()) {
        return 0;
    } else {
        return maxHeap.top();
    }
}

int main() {
    vector<int> stones = {2,7,4,1,8,1};

    cout << lastStoneWeight(stones) << endl;
    
    return 0;
}
