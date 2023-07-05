// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0, zeros = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            zeros += nums[r] == 0;
            while (zeros == 2) {
                zeros -= nums[l++] == 0;
            }
            res = max(res, r - l + 1);
        }
        return zeros == 0 ? nums.size() - 1 : res - 1;
    }
};