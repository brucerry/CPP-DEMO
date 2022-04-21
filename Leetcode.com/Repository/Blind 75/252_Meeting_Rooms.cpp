// https://leetcode.com/problems/meeting-rooms/

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
// space: O(log(n)) to O(n) for sorting

class Solution {
public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
      return a.start < b.start;
    });

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i - 1].end > intervals[i].start)
        return false;
    }
    return true;
  }
};