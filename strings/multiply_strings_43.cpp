#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }

    int n = num1.size();
    int m = num2.size();
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string s = "";
    for (int p : result) {
        if (!(s.empty() && p == 0)) {
            s.push_back(p + '0');
        }
    }

    return s.empty() ? "0" : s;
}

int main() {
    string n1 = "123456789123456789";
    string n2 = "987654321987654321";
    
    cout << multiply(n1, n2) << endl;
    return 0;
}