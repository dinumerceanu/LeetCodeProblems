#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    vector<char> s_vec(s.begin(), s.end());
    int left = 0;
    int max_len = 0;

    for (int i = 0; i < s_vec.size(); i++) {
        if (map.find(s_vec[i]) != map.end()) {
            left = max(left, map.at(s_vec[i]) + 1);
        }
        map[s_vec[i]] = i;
        max_len = max(max_len, i - left + 1);
    }

    return max_len;
}

int main() {
    string s = "tmmzuxt";
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}
