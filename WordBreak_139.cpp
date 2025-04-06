#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            string word = s.substr(j, i - j);
            if (dp[j] && dict.count(word)) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    cout<<wordBreak(s, wordDict);

    return 0;
}