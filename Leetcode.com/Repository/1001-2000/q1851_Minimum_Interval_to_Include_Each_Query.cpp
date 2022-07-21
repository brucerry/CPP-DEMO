// https://leetcode.com/problems/minimum-interval-to-include-each-query/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// n = size of intervals
// q = size of queries
// time: O(n * log(n) + q * log(q) + q * log(n))
// space: O(n + q)

class Solution {
public:
  vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    int n = intervals.size();
    int q = queries.size();
    
    vector<pair<int, int>> newQueries (q); // val, index
    for (int i = 0; i < q; i++)
      newQueries[i] = { queries[i], i };
    sort(newQueries.begin(), newQueries.end());
    
    sort(intervals.begin(), intervals.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // size, end
    
    int j = 0;
    vector<int> result (q);
    for (const auto& [ val, index ] : newQueries) {
      while (j < n and intervals[j][0] <= val) {
        minHeap.emplace(intervals[j][1] - intervals[j][0] + 1, intervals[j][1]);
        j++;
      }
      
      while (minHeap.size() and minHeap.top().second < val)
        minHeap.pop();
      
      result[index] = minHeap.size() ? minHeap.top().first : -1;
    }
    
    return result;
  }
};