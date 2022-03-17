// https://leetcode.com/problems/task-scheduler/

#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// t = len of tasks
// m = # of groups in tasks (A - Z at most 26 groups)
// time: O(t + m * n)
// space: O(m)

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    priority_queue<int> ready; // count
    queue<pair<int, int>> cooldown; // (count, time of ready-to-go)
    int timeNeeded = 0;

    for (char& ch : tasks) {
      freq[ch]++;
    }

    for (auto& [ ch, count ] : freq) {
      ready.push(count);
    }

    while (ready.size() || cooldown.size()) {
      if (ready.size()) {
        int count = ready.top();
        ready.pop();

        if (--count) {
          cooldown.push({count, timeNeeded + n});
        }
      }

      if (cooldown.size() && cooldown.front().second == timeNeeded) {
        ready.push(cooldown.front().first);
        cooldown.pop();
      }

      timeNeeded++;
    }

    return timeNeeded;
  }
};