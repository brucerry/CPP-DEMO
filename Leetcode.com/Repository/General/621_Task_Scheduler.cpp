// https://leetcode.com/problems/task-scheduler/

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// t = len of tasks
// m = # of groups in tasks (A - Z at most 26 groups)
// time: O(t)
// space: O(m)

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> taskCount;
    priority_queue<int> ready; // count
    queue<pair<int, int>> cooldown; // count, time of ready-to-go
    
    for (const char& task : tasks) {
      taskCount[task]++;
    }
    
    for (const auto& [ _, count ] : taskCount) {
      ready.emplace(count);
    }
    
    int timeNeeded = 0;
    
    while (ready.size() || cooldown.size()) {
      if (ready.size()) {
        const int& count = ready.top();
      
        if (count - 1) {
          cooldown.emplace(count - 1, timeNeeded + n);
        }

        ready.pop();
      }      
      
      if (cooldown.size() && cooldown.front().second == timeNeeded) {
        ready.emplace(cooldown.front().first);
        cooldown.pop();
      }
      
      timeNeeded++;
    }
    
    return timeNeeded;
  }
};