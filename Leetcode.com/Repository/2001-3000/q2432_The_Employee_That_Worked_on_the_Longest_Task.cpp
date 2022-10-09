// https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int hardestWorker(int n, vector<vector<int>>& logs) {
    int result = 0, longest = 0, curTime = 0;
    for (const auto& log : logs) {
      int id = log[0], end = log[1];
      int workTime = end - curTime;
      curTime = end;
      if (workTime > longest or (workTime == longest and id < result)) {
        longest = workTime;
        result = id;
      }
    }
    return result;
  }
};