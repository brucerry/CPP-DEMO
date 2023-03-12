// https://leetcode.com/problems/minimum-time-to-complete-all-tasks/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n) + n * end)
// space: O(end)

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        bool slots[2001] = {};
        for (const auto& task : tasks) {
            int start = task[0];
            int end = task[1];
            int duration = task[2];
            duration -= count(begin(slots) + start, begin(slots) + end + 1, true);
            for (int i = end; duration > 0; i--) {
                duration -= !slots[i];
                slots[i] = true;
            }
        }
        return count(begin(slots), end(slots), true);
    }
};