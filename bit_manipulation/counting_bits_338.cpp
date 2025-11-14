#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n) {
    vector<int> res(n + 1);
    
    for (int i = 1; i <= n; i++) {
        res[i] = res[i & (i - 1)] + 1;
    }

    return res;
}

int main() {
    vector<int> res = countBits(5);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
