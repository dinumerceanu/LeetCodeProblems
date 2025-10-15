#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int gasSum = 0;
    int costSum = 0;

    for (int i = 0; i < n; i++) {
        gasSum += gas[i];
        costSum += cost[i];
    }

    if (gasSum < costSum) {
        return -1;
    }

    int tank = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        tank += gas[i];
        tank -= cost[i];
        
        if (tank < 0) {
            start = i + 1;
            tank = 0; 
        }
    }

    return start;
}

int main() {
    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};

    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}
