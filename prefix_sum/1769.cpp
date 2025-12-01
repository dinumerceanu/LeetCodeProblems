#include <iostream>
#include <vector>

using namespace std;

vector<int> minOperations(string boxes) {
    vector<int> res(boxes.size(), 0);

    for (int i = 0; i < boxes.size(); i++) {
        if (boxes[i] == '1') {
            for (int j = 0; j < boxes.size(); j++) {
                res[j] += abs(i - j);
            }
        }
    }
    
    return res;
}

int main() {
    string s = "001011";

    vector<int> res = minOperations(s);

    for (const auto& elem : res) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
