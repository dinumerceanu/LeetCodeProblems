#include <iostream>
#include <vector>

using namespace std;

int fib_aux(int n, vector<int>& calls) {
    if (n == 0 || n == 1) {
        return n;
    }

    if (calls[n] != -1) {
        return calls[n];
    }

    calls[n] = fib_aux(n - 1, calls) + fib_aux(n - 2, calls);

    return calls[n];
}

int fib(int n) {
    vector<int> calls(n + 1, -1);
    
    return fib_aux(n, calls);
}

int main() {
    cout << fib(6) << endl;

    return 0;
}
