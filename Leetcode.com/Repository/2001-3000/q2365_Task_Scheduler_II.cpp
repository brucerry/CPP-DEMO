// https://leetcode.com/problems/task-scheduler-ii/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  long long taskSchedulerII(vector<int>& tasks, int space) {
    unordered_map<int, long long> next; // task, available day
    long long curDay = 0;
    for (const int& task : tasks) {
      curDay = max(curDay + 1, next[task]);
      next[task] = curDay + space + 1;
    }
    return curDay;
  }
};