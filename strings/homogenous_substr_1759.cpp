#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007LL;

int countHomogenous(string s) {
    vector<string> substrs;
    int i = 0;

    while (i < s.size()) {
        int j = i;

        string aux;
        while (j < s.size() && s[i] == s[j]) {
            aux.push_back(s[i]);
            j++;
        }

        substrs.push_back(aux);
        i = j;
    }

    long long sum = 0;
    for (int i = 0; i < substrs.size(); i++) {
        long long len = substrs[i].size();
        sum += ((len * (len + 1)) / 2) % MOD;
    }
    
    return sum;
}

int main() {
    string s = "abbcccaa";

    cout << countHomogenous(s) << endl;

    return 0;
}
