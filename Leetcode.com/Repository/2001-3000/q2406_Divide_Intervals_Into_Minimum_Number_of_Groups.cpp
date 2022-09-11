// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)
class MinHeap {
public:
  int minGroups(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    
    priority_queue<int, vector<int>, greater<>> minHeap; // right
    for (const auto& interval : intervals) {
      int left = interval[0], right = interval[1];
      if (minHeap.size() and minHeap.top() < left)
        minHeap.pop();
      minHeap.emplace(right);
    }
    
    return minHeap.size();
  }
};

// time: O(n * log(n))
// space: O(n)
class MeetingRoom {
public:
  int minGroups(vector<vector<int>>& intervals) {
    int n = intervals.size();
    
    vector<int> starts (n), ends (n);
    for (int i = 0; i < n; i++) {
      starts[i] = intervals[i][0];
      ends[i] = intervals[i][1];
    }
    
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    
    int groups = 0;
    for (int s = 0, e = 0, cur = 0; s < n; ) {
      int start = starts[s], end = ends[e];
      if (start <= end) {
        groups = max(groups, ++cur);
        s++;
      }
      else {
        cur--;
        e++;
      }
    }
    
    return groups;
  }
};