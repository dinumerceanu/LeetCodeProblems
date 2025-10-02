#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    unordered_map<char, char> s_to_t;
    unordered_map<char, char> t_to_s;

    for (int i = 0; i < s.size(); i++) {
        char c1 = s[i], c2 = t[i];

        if (s_to_t.count(c1) && s_to_t[c1] != c2) {
            return false;
        }
        
        if (t_to_s.count(c2) && t_to_s[c2] != c1) {
            return false;
        }

        s_to_t[c1] = c2;
        t_to_s[c2] = c1;
    }

    return true;
}

int main() {
    string s1 = "egg", t1 = "add", s2 = "foo", t2 = "bar";

    cout << isIsomorphic(s1, t1) << endl << isIsomorphic(s2, t2) << endl;

    return 0;
}
