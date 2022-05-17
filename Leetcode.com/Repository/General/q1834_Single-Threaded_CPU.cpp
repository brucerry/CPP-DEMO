// https://leetcode.com/problems/single-threaded-cpu/

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    for (int i = 0; i < tasks.size(); i++) {
      tasks[i].emplace_back(i);
    }
    sort(tasks.begin(), tasks.end()); // start, duration, task index
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> ready; // duration, task index
    
    int i = 0;
    unsigned int curTime = tasks[0][0];
    vector<int> tasksOrder;
    while (i < tasks.size() or ready.size()) {
      while (i < tasks.size() and tasks[i][0] <= curTime) {
        ready.emplace(tasks[i][1], tasks[i][2]);
        i++;
      }
      
      if (ready.size()) {
        auto [ duration, taskIndex ] = ready.top();
        ready.pop();
        
        tasksOrder.emplace_back(taskIndex);
        curTime += duration;
      }
      else {
        curTime = tasks[i][0];
      }
    }
    
    return tasksOrder;
  }
};