#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int n = prices.size();
    vector<int> sold(n, 0), held(n, 0), rest(n, 0);

    held[0] = -prices[0];

    for (int i = 1; i < n; ++i) {
        sold[i] = held[i - 1] + prices[i];
        held[i] = max(held[i - 1], rest[i - 1] - prices[i]);
        rest[i] = max(rest[i - 1], sold[i - 1]);
    }

    return max(sold[n - 1], rest[n - 1]);
}

int main() {
    vector<int> prices = {2,1,4,5,2,9,7};
    cout<<maxProfit(prices);

    return 0;
}