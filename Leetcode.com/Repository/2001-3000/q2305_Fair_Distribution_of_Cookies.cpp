// https://leetcode.com/problems/fair-distribution-of-cookies/

#include <vector>
using namespace std;

// time: O(k * 2^n * n)
// space: O(2^n)

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();

        vector<int> sums (1 << n);
        for (int mask = 0; mask < 1 << n; mask++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    sum += cookies[i];
            }
            sums[mask] = sum;
        }

        vector<int> dp (1 << n, INT_MAX), tmp;
        dp[0] = 0;

        for (int child = 1; child <= k; child++) {
            tmp = dp;
            for (int mask = 0; mask < 1 << n; mask++) {
                for (int submask = mask; submask; submask = (submask - 1) & mask) {
                    tmp[mask] = min(tmp[mask], max(sums[submask], dp[submask ^ mask]));
                }
            }
            dp = tmp;
        }

        return dp.back();
    }
};