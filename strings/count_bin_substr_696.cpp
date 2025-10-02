#include <iostream>
#include <vector>

using namespace std;

int countBinarySubstrings(string s) {
    vector<int> aux;
    int i = 0;

    while (i < s.size()) {
        int j = i;
        
        while (j < s.size() && s[j] == s[i]) {
            j++;
        }

        aux.push_back(j - i);
        i = j;
    }

    int res = 0;
    for (int i = 0; i < aux.size() - 1; i++) {
        res += min(aux[i], aux[i + 1]);
    }

    return res;
}

int main() {
    string s = "00110011";

    cout << countBinarySubstrings(s) << endl;
    
    return 0;
}
