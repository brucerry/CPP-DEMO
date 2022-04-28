// https://leetcode.com/problems/task-scheduler/

#include <vector>
#include <queue>
#include <array>
using namespace std;

// t = len of tasks
// time: O(t)
// space: O(1)

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    array<int, 26> charCount { 0 };
    
    for (const char& c : tasks) {
      charCount[c - 'A']++;
    }
    
    priority_queue<int> ready; // count
    
    for (const int& count : charCount) {
      if (count)
        ready.emplace(count);
    }
    
    queue<pair<int, int>> cooldown; // count, next ready time
    
    int ans = 0;
    
    while (ready.size() or cooldown.size()) {
      if (ready.size()) {
        int count = ready.top();
        ready.pop();
        
        if (--count)
          cooldown.emplace(count, ans + n);
      }
      
      if (cooldown.size() and cooldown.front().second == ans) {
        ready.emplace(cooldown.front().first);
        cooldown.pop();
      }
      
      ans++;
    }
    
    return ans;
  }
};