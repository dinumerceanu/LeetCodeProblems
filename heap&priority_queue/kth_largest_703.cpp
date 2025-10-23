#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        k_size = k;
        
        for (int num : nums) {
            add(num); 
        }
    }
    
    int add(int val) {
        if (minHeap.size() < k_size) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        
        if (minHeap.size() < k_size) {
            return -1;
        }
        
        return minHeap.top();
    }

private:
    int k_size;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

int main() {
    vector<int> initial_nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, initial_nums);

    cout << "Add 3: " << kthLargest.add(3) << endl;
    cout << "Add 5: " << kthLargest.add(5) << endl;
    cout << "Add 10: " << kthLargest.add(10) << endl;
    cout << "Add 9: " << kthLargest.add(9) << endl;
    cout << "Add 4: " << kthLargest.add(4) << endl;

    return 0;
}
