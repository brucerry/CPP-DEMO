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
    int n = intervals.size();
    
    vector<int> starts (n);
    vector<int> ends (n);
    for (int i = 0; i < n; i++) {
      starts[i] = intervals[i].start;
      ends[i] = intervals[i].end;
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int room = 0, result = 0;
    int i = 0, j = 0;
    while (i < n) {
      if (starts[i] < ends[j]) {
        room++;
        i++;
        result = max(result, room);
      }
      else {
        room--;
        j++;
      }
    }

    return result;
  }
};