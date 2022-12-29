// https://leetcode.com/problems/single-threaded-cpu/

#include <vector>
#include <algorithm>
#include <queue>
#include <array>
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
    sort(tasks.begin(), tasks.end());

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> minHeap; // procTime, index
    vector<int> res;
    long curTime = tasks[0][0], i = 0;
    while (i < n or minHeap.size()) {
      curTime = minHeap.empty() ? max(curTime, (long)tasks[i][0]) : curTime;
      while (i < n and curTime >= tasks[i][0]) {
        minHeap.push({ tasks[i][1], tasks[i][2] });
        i++;
      }
      auto [ procTime, index ] = minHeap.top();
      minHeap.pop();
      res.emplace_back(index);
      curTime += procTime;
    }
    return res;
  }
};