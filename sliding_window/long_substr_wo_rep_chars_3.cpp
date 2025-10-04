#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int longest = 0;
    int left = 0;

    for (int right = 0; right < s.size(); right++) {
        if (set.find(s[right]) == set.end()) {
            set.insert(s[right]);

            if (right - left + 1 > longest) {
                longest = right - left + 1;
            }
        } else {
            while (left < right && set.find(s[right]) != set.end()) {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
        }
    }

    return longest;
}

int main() {
    string s = "bbbb";

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}
