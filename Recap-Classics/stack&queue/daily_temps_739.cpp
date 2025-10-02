#include <iostream>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(), 0);
    vector<int> stack;

    for (int i = 0; i < temperatures.size(); i++) {
        if (stack.empty() || temperatures[i] < temperatures[stack.back()]) {
            stack.push_back(i);
        } else {
            while (!stack.empty() && temperatures[i] > temperatures[stack.back()]) {
                res[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
    }
    
    return res;
}

int main() {
    vector<int> temps = {73,74,75,71,69,72,76,73};
    vector<int> res = dailyTemperatures(temps);

    for (int i = 0; i < temps.size(); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
