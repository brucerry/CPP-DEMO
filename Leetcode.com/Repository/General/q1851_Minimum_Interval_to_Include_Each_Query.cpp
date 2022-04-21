// https://leetcode.com/problems/minimum-interval-to-include-each-query/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    sort(intervals.begin(), intervals.end());
    
    vector<pair<int, int>> newQueries (queries.size());
    for (int i = 0; i < queries.size(); i++) {
      newQueries[i] = { queries[i], i };
    }
    sort(newQueries.begin(), newQueries.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // len, right-index
    int j = 0;
    
    vector<int> ans (queries.size());
    
    for (const auto& [ num, originalIndex ] : newQueries) {
      while (j < intervals.size() && intervals[j][0] <= num) {
        minHeap.emplace(intervals[j][1] - intervals[j][0] + 1, intervals[j][1]);
        j++;
      }
      while (minHeap.size() && minHeap.top().second < num) {
        minHeap.pop();
      }

      ans[originalIndex] = minHeap.size() ? minHeap.top().first : -1;
    }
    
    return ans;
  }
};