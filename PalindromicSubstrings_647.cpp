#include <iostream>
#include <vector>

using namespace std;

int countSubstrings(string s) {
    if (s.length() == 1) return 1;
    if (s.length() == 2 && s[0] != s[1]) return 2;
    if (s.length() == 2 && s[0] == s[1]) return 3;

    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    int count = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        for (int j = i; j < s.length(); j++) {
            if (s[i] == s[j]) {
                if (j - i <= 2) {
                    dp[i][j] = 1;
                    count++;
                } else if (dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    string s = "aaa";
    cout<<countSubstrings(s);

    return 0;
}