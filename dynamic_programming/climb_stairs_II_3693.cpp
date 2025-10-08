#include <iostream>
#include <vector>

using namespace std;

int cost(int i, int j, vector<int>& costs) {
    return (j - i) * (j - i) + costs[j - 1];
}

int climbStairs(int n, vector<int>& costs) {
    int a = 0, b, c;

    for (int i = 1; i <= n; i++) {
        int c1 = 1e9, c2 = 1e9, c3 = 1e9;

        if (i >= 1) {
            c1 = a + cost(i - 1, i, costs);
        }
        if (i >= 2) {
            c2 = b + cost(i - 2, i, costs);
        }
        if (i >= 3) {
            c3 = c + cost(i - 3, i, costs);
        }

        c = b;
        b = a;
        a = min(c1, min(c2, c3));
    }

    return a;
}

int main() {
    int n = 4;
    vector<int> costs = {5,1,6,2};

    cout << climbStairs(n, costs) << endl;

    return 0;
}
