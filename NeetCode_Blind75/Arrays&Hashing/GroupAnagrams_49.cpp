#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> anagramGroups;

    for (auto word : strs) {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        anagramGroups[sortedWord].push_back(word);
    }

    vector<vector<string>> result;
    for (auto entry : anagramGroups) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {
    ifstream fin("file.in");
    ofstream fout("file.out");

    vector<string> strs;
    string str_in;
    while (fin >> str_in) {
        strs.push_back(str_in);
    }

    vector<vector<string>> res = groupAnagrams(strs);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}