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
    sort(tasks.begin(), tasks.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> availableTasks; // duration, task
    
    vector<int> tasksOrder;
    
    int i = 0;
    unsigned int curTime = tasks[0][0];
    while (i < tasks.size() or availableTasks.size()) {
      while (i < tasks.size() and tasks[i][0] <= curTime) {
        availableTasks.emplace(tasks[i][1], tasks[i][2]);
        i++;
      }
      
      if (availableTasks.size()) {
        auto [ duration, task ] = availableTasks.top();
        availableTasks.pop();
        
        tasksOrder.emplace_back(task);
        curTime += duration;
      }
      else {
        curTime = tasks[i][0];
      }
    }
    
    return tasksOrder;
  }
};