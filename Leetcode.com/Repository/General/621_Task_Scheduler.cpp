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
    for (const char& c : tasks)
      charCount[c - 'A']++;
    
    priority_queue<int> ready; // count
    for (const int& count : charCount) {
      if (count)
        ready.emplace(count);
    }
    
    queue<pair<int, int>> cooldown; // count, ready-to-go time
    
    int curTime = 0;
    while (ready.size() or cooldown.size()) {
      if (ready.size()) {
        int count = ready.top();
        ready.pop();
        
        if (--count) {
          cooldown.emplace(count, curTime + n);
        }
      }
      
      if (cooldown.size()) {
        auto [ count, time ] = cooldown.front();
        
        if (time == curTime) {
          ready.emplace(count);
          cooldown.pop();
        }
      }
      
      curTime++;
    }
    
    return curTime;
  }
};