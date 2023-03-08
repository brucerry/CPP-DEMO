// https://leetcode.com/problems/minimum-time-to-complete-trips/

#include <vector>
using namespace std;

// time: O(n * log(1e14))
// space: O(1)

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long l = 1, r = 1e14;
        while (l < r) {
            long m = (l + r) / 2;
            if (canComplete(time, totalTrips, m))
                r = m;
            else
                l = m + 1;
        }
        return r;
    }

private:
    bool canComplete(vector<int>& time, int totalTrips, long testTime) {
        long trips = 0;
        for (const int& t : time) {
            trips += testTime / t;
        }
        return trips >= totalTrips;
    }
};