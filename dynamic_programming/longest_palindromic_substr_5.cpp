#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
    string res;
    int maxLength = 0;

    for (int i = 0; i < s.size(); i++) {
        int l = i, r = i;

        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > maxLength) {
                res = s.substr(l, r - l + 1);
                maxLength = r- l + 1;
            }
            
            l--;
            r++;
        }

        l = i, r = i + 1;

        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > maxLength) {
                res = s.substr(l, r - l + 1);
                maxLength = r- l + 1;
            }
            
            l--;
            r++;
        }
    }

    return res;
}

int main() {
    string s = "babad";

    cout << longestPalindrome(s) << endl;

    return 0;
}
