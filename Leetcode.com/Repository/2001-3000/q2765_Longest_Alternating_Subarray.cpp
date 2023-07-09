// https://leetcode.com/problems/longest-alternating-subarray/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int res = -1;
        for (int l = 0, r = 1; r < nums.size(); r++) {
            if (nums[l] + (r - l) % 2 != nums[r]) {
                l = r - (nums[r-1] == nums[r] - 1);
            }
            if (r - l + 1 > 1)
                res = max(res, r - l + 1);
        }
        return res;
    }
};