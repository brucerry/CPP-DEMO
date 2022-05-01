// https://leetcode.com/problems/minimum-interval-to-include-each-query/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// n = len of intervals
// q = len of queries
// time: O(n * log(n) + q * log(q))
// space: O(n + q)

class Solution {
public:
  vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    sort(intervals.begin(), intervals.end());
    
    vector<pair<int, int>> newQueries (queries.size()); // num, index
    for (int i = 0; i < queries.size(); i++) {
      newQueries[i] = { queries[i], i };
    }
    
    sort(newQueries.begin(), newQueries.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // len, end-index
    
    vector<int> ans (queries.size());
    
    int j = 0;
    
    for (const auto& [ num, i ] : newQueries) {
      while (j < intervals.size() and intervals[j][0] <= num) {
        minHeap.emplace(intervals[j][1] - intervals[j][0] + 1, intervals[j][1]);
        j++;
      }
      
      while (minHeap.size() and minHeap.top().second < num)
        minHeap.pop();
      
      if (minHeap.size())
        ans[i] = minHeap.top().first;
      else
        ans[i] = -1;
    }
    
    return ans;
  }
};