#include <iostream>
#include <vector>

using namespace std;

long long getDescentPeriods(vector<int>& prices) {
    long long ans = 1, dp = 1;

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] == prices[i - 1] - 1) {
            dp++;
        } else {
            dp = 1;
        }

        ans += dp;
    }

    return ans;
}

int main() {
    vector<int> prices = {3,2,1,4};

    cout << getDescentPeriods(prices) << endl;

    return 0;
}
