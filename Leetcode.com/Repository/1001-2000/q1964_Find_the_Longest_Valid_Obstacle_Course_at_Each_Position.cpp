// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> dp, res;
        for (int ob : obstacles) {
            int pos = upper_bound(dp.begin(), dp.end(), ob) - dp.begin();
            if (pos == dp.size())
                dp.emplace_back(ob);
            else
                dp[pos] = ob;
            res.emplace_back(pos + 1);
        }
        return res;
    }
};