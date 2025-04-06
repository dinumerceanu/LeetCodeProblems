#include <iostream>
#include <vector>

using namespace std;

int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    vector<int> dp(s.length() + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= s.length(); i++) {
        int oneDigit = s[i - 1] - '0';
        int twoDigits = stoi(s.substr(i - 2, 2));

        if (oneDigit >= 1) {
            dp[i] += dp[i - 1];
        }

        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[s.length()];
}

int main() {
    string s = "1123";
    cout<<numDecodings(s);

    return 0;
}