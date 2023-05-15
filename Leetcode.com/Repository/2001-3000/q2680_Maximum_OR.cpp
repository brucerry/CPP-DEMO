// https://leetcode.com/problems/maximum-or/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix (n);
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i+1] | nums[i+1];
        }

        long res = 0, prefix = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, prefix | ((long)nums[i] << k) | suffix[i]);
            prefix |= nums[i];
        }

        return res;
    }
};