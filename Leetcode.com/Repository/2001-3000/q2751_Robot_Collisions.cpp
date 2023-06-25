// https://leetcode.com/problems/robot-collisions/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = directions.size();

        vector<int> idx (n);
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return positions[i] < positions[j];
        });

        vector<int> state;
        for (int i : idx) {
            while (state.size() and directions[state.back()] == 'R' and directions[i] == 'L' and healths[i]) {
                int diff = healths[state.back()] - healths[i];
                if (diff > 0) {
                    healths[i] = 0;
                    healths[state.back()]--;
                }
                else if (diff < 0) {
                    healths[i]--;
                    healths[state.back()] = 0;
                    state.pop_back();
                }
                else {
                    healths[i] = 0;
                    healths[state.back()] = 0;
                    state.pop_back();
                }
            }
            if (healths[i])
                state.emplace_back(i);
        }
        
        vector<int> res;
        for (int health : healths) {
            if (health)
                res.emplace_back(health);
        }

        return res;
    }
};