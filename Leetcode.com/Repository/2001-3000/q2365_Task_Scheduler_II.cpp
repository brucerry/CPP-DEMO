// https://leetcode.com/problems/task-scheduler-ii/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> next; // task, next available day
        long long curday = 0;
        for (int& task : tasks) {
            curday = max(curday + 1, next[task]);
            next[task] = curday + 1 + space;
        }
        return curday;
    }
};