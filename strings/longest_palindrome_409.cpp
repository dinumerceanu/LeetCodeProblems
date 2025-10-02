#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> freq;

    for (int i = 0; i < s.size(); i++) {
        if (freq.find(s[i]) == freq.end()) {
            freq[s[i]] = 1;
        } else {
            freq[s[i]] += 1;
        }
    }

    int longest = 0;
    bool odd = false;

    for (auto& p : freq) {
        if (p.second % 2 == 0) {
            longest += p.second;
        } else {
            odd = true;
            longest += p.second - 1;
        }
    }

    if (odd) {
        longest += 1;
    }

    return longest;
}

int main() {
    string s = "abccccdd";

    cout << longestPalindrome(s) << endl;
    
    return 0;
}
