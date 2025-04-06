#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
    if (s.length() == 1) return s;
    if (s.length() == 2 && s[0] == s[1]) return s;

    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));

    for (int i = s.length() - 1; i >= 0; i--) {
        for (int j = i; j < s.length(); j++) {
            if (s[i] == s[j]) {
                if (j - i <= 2) {
                    dp[i][j] = 1;
                } else if (dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                }
            }
        }
    }

    int len = 1, start = 0;

    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            if (dp[i][j] == 1 && (j - i + 1 > len)) {
                start = i;
                len = j - i + 1;
            }
        }
    }
    return s.substr(start, len);  
}

int main() {
    string s = "aacabdkacaa";
    cout<<longestPalindrome(s);

    return 0;
}