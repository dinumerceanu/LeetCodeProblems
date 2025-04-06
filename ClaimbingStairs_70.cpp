#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    vector<int> dp(n + 2);
    dp[0] = 0;
    dp[1] = 1;
    int i = 2;
    while (i <= n + 1) {
        dp[i] = dp[i - 1] + dp[i - 2];
        i++;
    }
    return dp[n + 1];
}

int main() {
    int n = 4;
    cout<<climbStairs(n);

    return 0;
}