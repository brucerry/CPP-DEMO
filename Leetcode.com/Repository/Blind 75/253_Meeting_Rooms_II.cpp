// https://leetcode.com/problems/meeting-rooms-ii/

#include <vector>
#include <algorithm>
using namespace std;

class Interval {
public:
  int start;
  int end;
  
  Interval(int start, int end) : start(start), end(end) {}
};

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int minMeetingRooms(vector<Interval>& intervals) {
    vector<int> starts (intervals.size());
    vector<int> ends (intervals.size());

    for (int i = 0; i < intervals.size(); i++) {
      starts[i] = intervals[i].start;
      ends[i] = intervals[i].end;
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
  
    int s = 0, e = 0;
    int count = 0;
    int ans = 0;

    while (s < starts.size()) {
      if (starts[s] < ends[e]) {
        count++;
        s++;
        ans = max(ans, count);
      }
      else {
        count--;
        e++;
      }
    }

    return ans;
  }
};