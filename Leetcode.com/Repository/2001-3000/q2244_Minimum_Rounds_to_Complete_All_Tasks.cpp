// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> taskCount; // task, count
    for (const int& task : tasks) {
      taskCount[task]++;
    }
    
    int res = 0;
    for (const auto& [ _, count ] : taskCount) {
      if (count == 1)
        return -1;
      res += (count + 3 - 1) / 3;
    }
    return res;
  }
};