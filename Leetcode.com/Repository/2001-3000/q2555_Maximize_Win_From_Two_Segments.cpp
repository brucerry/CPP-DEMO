// https://leetcode.com/problems/maximize-win-from-two-segments/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int maximizeWin(vector<int>& pos, int k) {
        int n = pos.size(), res = 0;
        vector<int> dp (n);
        for (int l = 0, r = 0; r < n; r++) {
            while (pos[r] - pos[l] > k) {
                l++;
            }
            dp[r] = max(r - l + 1, r - 1 >= 0 ? dp[r-1] : 0);
            res = max(res, r - l + 1 + (l - 1 >= 0 ? dp[l-1] : 0));
        }
        return res;
    }
};