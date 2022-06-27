// https://leetcode.com/problems/minimum-time-to-complete-trips/

#include <vector>
using namespace std;

// time: O(n * log(min(time) * totalTrips))
// space: O(1)

class Solution {
public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    long long l = 1, r = INT_MAX;
    for (const long long& t : time)
      r = min(r, t);
    r *= totalTrips;
    
    while (l < r) {
      long long m = l + ((r - l) >> 1);
      if (canComplete(time, totalTrips, m))
        r = m;
      else
        l = m + 1;
    }
    return r;
  }
  
private:
  bool canComplete(vector<int>& time, int totalTrips, long long minTime) {
    long long trip = 0;
    for (const int& t : time) {
      trip += minTime / t;
    }
    return trip >= totalTrips;
  }
};