#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> counts;
    
    for (char task : tasks) {
        counts[task]++;
    }

    priority_queue<int> readyQueue;
    
    for (auto const& [task, count] : counts) {
        readyQueue.push(count);
    }

    queue<pair<int, int>> waitingQueue;

    int time = 0;
    
    while (!readyQueue.empty() || !waitingQueue.empty()) {
        time++;

        if (!readyQueue.empty()) {
            int current_count = readyQueue.top();
            readyQueue.pop();

            current_count--;

            if (current_count > 0) {
                int release_time = time + n;
                waitingQueue.push({release_time, current_count});
            }
        }

        if (!waitingQueue.empty() && waitingQueue.front().first <= time) {
            int count_to_resume = waitingQueue.front().second;
            waitingQueue.pop();
            readyQueue.push(count_to_resume);
        }
    }
    
    return time;
}

int main() {
    // vector<char> tasks = {'A','B','A','B','B','C','C'};
    // vector<char> tasks = {'A','B','A'};
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    cout << leastInterval(tasks, n) << endl;

    return 0;
}
