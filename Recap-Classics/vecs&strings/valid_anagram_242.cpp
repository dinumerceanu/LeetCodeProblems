#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    unordered_map<char, int> freq_s;
    unordered_map<char, int> freq_t;

    for (char c : s) {
        if (freq_s.find(c) != freq_s.end()) {
            freq_s[c] += 1;
        } else {
            freq_s[c] = 0;
        }
    }

    for (char c : t) {
        if (freq_t.find(c) != freq_t.end()) {
            freq_t[c] += 1;
        } else {
            freq_t[c] = 0;
        }
    }

    for (auto& p : freq_s) {
        if (freq_t.find(p.first) == freq_t.end()) {
            return false;
        } else {
            if (freq_t[p.first] != p.second) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaramx";

    cout << isAnagram(s, t) << endl;

    return 0;
}
