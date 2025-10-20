#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) {
        return false;
    }

    unordered_map<char, int> map_s1;
    unordered_map<char, int> map_substr_s2;
    bool res = false;

    for (char c : s1) {
        map_s1[c]++;
    }

    int i = 0, j = s1.size() - 1;
    for (int k = i; k < j; k++) {
        map_substr_s2[s2[k]]++;
    }

    while (j < s2.size()) {
        map_substr_s2[s2[j]]++;
        
        if (map_s1 == map_substr_s2) {
            return true;
        }

        if (map_substr_s2[s2[i]] == 1) {
            map_substr_s2.erase(s2[i]);
        } else {
            map_substr_s2[s2[i]]--;
        }

        i++;
        j++;
    }

    return res;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << checkInclusion(s1, s2) << endl;

    return 0;
}
