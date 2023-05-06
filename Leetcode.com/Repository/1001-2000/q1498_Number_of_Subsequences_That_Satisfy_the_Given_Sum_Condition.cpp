// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, mod = 1e9 + 7, n = nums.size();
        vector<int> pows (n, 1);
        for (int i = 1; i < n; i++) {
            pows[i] = pows[i-1] * 2 % mod;
        }
        for (int l = 0, r = n - 1; l <= r; l++) {
            while (l <= r and nums[l] + nums[r] > target) {
                r--;
            }
            if (l <= r and nums[l] + nums[r] <= target) {
                res = (res + pows[r - l]) % mod;
            }
        }
        return res;
    }
};