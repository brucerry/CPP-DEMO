// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res = INT_MAX;
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones)
            return n - ones;
        for (int l = 0; l < n; l++) {
            int GCD = nums[l];
            for (int r = l + 1; r < n; r++) {
                GCD = gcd(GCD, nums[r]);
                if (GCD == 1)
                    res = min(res, r - l + n - 1);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};