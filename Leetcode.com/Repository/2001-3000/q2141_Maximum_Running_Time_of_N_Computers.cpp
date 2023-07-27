// https://leetcode.com/problems/maximum-running-time-of-n-computers/

#include <vector>
using namespace std;

// time: O(n * log(1e14))
// space: O(1)

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long l = 1, r = 1e14;
        while (l < r) {
            long m = (l + r + 1) / 2;
            if (solve(n, batteries, m))
                l = m;
            else
                r = m - 1;
        }
        return l;
    }

private:
    bool solve(int n, vector<int>& batteries, long test_mins) {
        long power = 0;
        for (long batt : batteries) {
            power += min(batt, test_mins);
        }
        return power >= test_mins * n;
    }
};