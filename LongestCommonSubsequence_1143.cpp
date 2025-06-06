#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
    for (int i = 1; i <= text1.length(); i++) {
        for (int j = 1; j <= text2.length(); j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[text1.length()][text2.length()];
}

int main() {
    string text1 = "abcde", text2 = "ace";
    cout<<longestCommonSubsequence(text1, text2);

    return 0;
}