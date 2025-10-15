#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int jump(vector<int>& nums) {
    if (nums.size() == 0 || nums.size() == 1) {
        return 0;
    }

    deque<int> q; 
    vector<bool> visited(nums.size(), false);
    
    q.push_back(0);
    visited[0] = true;
    int min_jumps = 0;

    cout << nums[0] << endl; 

    while (!q.empty()) {
        int level_size = q.size();
        bool first_on_level = true;
        
        if (visited.back()) {
            break; 
        }

        min_jumps++;
        
        for (int k = 0; k < level_size; k++) {
            int current_index = q.front();
            q.pop_front();
            
            int max_jump = nums[current_index];

            for (int next_index = current_index + 1; 
                 next_index <= current_index + max_jump && next_index < nums.size(); 
                 next_index++) {
                
                if (!visited[next_index]) {
                    q.push_back(next_index);
                    visited[next_index] = true;
                    
                    if (!first_on_level) {
                        cout << " ";
                    }

                    cout << nums[next_index];
                    first_on_level = false;

                    if (next_index == nums.size() - 1) {
                        cout << endl;
                        return min_jumps; 
                    }
                }
            }
        }
        
        if (!q.empty()) {
            cout << endl;
        }
    }
    
    return min_jumps; 
}

int main() {
    vector<int> nums = {2,3,1,1,4};

    cout << jump(nums) << endl;

    return 0;
}
