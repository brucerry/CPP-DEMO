// https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& n1, vector<int>& n2) {
        int res = 1;
        int dp1 = 1, dp2 = 1;
        for (int i = 1; i < n1.size(); i++) {
            int x11 = n1[i-1] <= n1[i] ? dp1 + 1 : 1;
            int x12 = n1[i-1] <= n2[i] ? dp1 + 1 : 1;
            int x21 = n2[i-1] <= n1[i] ? dp2 + 1 : 1;
            int x22 = n2[i-1] <= n2[i] ? dp2 + 1 : 1;
            dp1 = max(x11, x21);
            dp2 = max(x12, x22);
            res = max({ res, dp1, dp2 });
        }
        return res;
    }
};