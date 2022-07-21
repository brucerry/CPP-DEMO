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
    int n = tasks.size();
    
    for (int i = 0; i < n; i++) {
      tasks[i].emplace_back(i);
    }
    sort(tasks.begin(), tasks.end()); // start, duration, taskIndex
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> ready; // duration, taskIndex
    vector<int> order;
    unsigned int curTime = tasks[0][0], i = 0;
    while (order.size() < n) {
      while (i < n and tasks[i][0] <= curTime) {
        ready.emplace(tasks[i][1], tasks[i][2]);
        i++;
      }
      
      if (ready.size()) {
        auto [ duration, taskIndex] = ready.top();
        ready.pop();
        order.emplace_back(taskIndex);
        curTime += duration;
      }
      else
        curTime = tasks[i][0];
    }
    
    return order;
  }
};