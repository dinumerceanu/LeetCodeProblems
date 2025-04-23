#include <iostream>
#include <vector>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    vector<int> letters_s1_s2(26, 0);
    vector<int> letters_s3(26, 0);
    for (int i = 0; i < s1.length(); i++) {
        letters_s1_s2[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.length(); i++) {
        letters_s1_s2[s2[i] - 'a']++;
    }
    for (int i = 0; i < s3.length(); i++) {
        letters_s3[s3[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (letters_s1_s2[i] != letters_s3[i]) return false;
    }
    return true;
}

int main() {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
    cout<<isInterleave(s1, s2, s3);

    return 0;
}