#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum = 0;
    for (int i = 0; i < gas.size(); i++) {
        sum = sum + gas[i] - cost[i];
    }
    if (sum < 0) {
        return -1;
    }
    int i = 0, tank = 0, start_idx = -1, completed_cycle = 0;
    while (1) {
        if (i == gas.size() - 1) {
            completed_cycle = 1;
        }
        if (tank + gas[i] >= cost[i]) {
            if (start_idx == -1) {
                start_idx = i;
            }
            tank = tank + gas[i] - cost[i];
            i = (i + 1) % gas.size();
            if (i == start_idx) {
                return i;
            }
        } else {
            i = (i + 1) % gas.size();
            if (start_idx != -1) {
                start_idx = -1;
            }
            tank = 0;
        }
    }
}

int main() {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout<<canCompleteCircuit(gas, cost);

    return 0;
}