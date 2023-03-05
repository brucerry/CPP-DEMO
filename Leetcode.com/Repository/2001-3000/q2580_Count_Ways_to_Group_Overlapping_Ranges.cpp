// https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/

#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int res = 2, mod = 1e9 + 7;
        for (int i = 1; i < ranges.size(); i++) {
            int& prevleft = ranges[i-1][0];
            int& prevright = ranges[i-1][1];
            int& curleft = ranges[i][0];
            int& curright = ranges[i][1];
            if (curleft <= prevright and prevleft <= curright) {
                curleft = min(curleft, prevleft);
                curright = max(curright, prevright);
            }
            else {
                res = (res * 2) % mod;
            }
        }
        return res;
    }
};