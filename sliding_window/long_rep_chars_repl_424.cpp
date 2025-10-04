#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxFreq(unordered_map<char, int>& freq) {
    int max = 0;

    for (auto& f : freq) {
        if (f.second > max) {
            max = f.second;
        }
    }

    return max;
}

int characterReplacement(string s, int k) {
    int left = 0, right = 0;
    unordered_map<char, int> freq;
    int res = 0;

    while (right < s.size()) {
        if (freq.find(s[right]) == freq.end()) {
            freq[s[right]] = 1;
        } else {
            freq[s[right]]++;
        }

        if (right - left + 1 - maxFreq(freq) <= k && right - left + 1 > res) {
            res = right - left + 1;
        } else {
            freq[s[left]]--;
            left++;
        }

        right++;
    }
    
    return res;
}

int main() {
    string s = "ABABB";
    int k = 2;

    cout << characterReplacement(s, k) << endl;

    return 0;
}
