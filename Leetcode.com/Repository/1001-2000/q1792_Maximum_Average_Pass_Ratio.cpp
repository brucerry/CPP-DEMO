// https://leetcode.com/problems/maximum-average-pass-ratio/

#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(n) + extraStudents * log(n))
// space: O(n)

class Solution {
public:
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    priority_queue<pair<double, int>> maxHeap; // profit, index
    int n = classes.size();
    double sum = 0;
    for (int i = 0; i < n; i++) {
      double pass = classes[i][0];
      double total = classes[i][1];
      double ratio = pass / total;
      double profit = (pass + 1) / (total + 1) - ratio;
      maxHeap.emplace(profit, i);
      sum += ratio;
    }
    
    while (extraStudents--) {
      auto [ profit, i ] = maxHeap.top();
      maxHeap.pop();
      
      sum += profit;
      
      double pass = ++classes[i][0];
      double total = ++classes[i][1];
      double ratio = pass / total;
      double newProfit = (pass + 1) / (total + 1) - ratio;
      maxHeap.emplace(newProfit, i);
    }
    
    return sum / n;
  }
};