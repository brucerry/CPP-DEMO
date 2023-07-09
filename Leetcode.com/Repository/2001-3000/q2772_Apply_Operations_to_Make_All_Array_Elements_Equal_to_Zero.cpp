// https://leetcode.com/problems/apply-operations-to-make-all-array-elements-equal-to-zero/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size(), cursum = 0;
        for (int l = 0, r = 0; r < n; r++) {
            if (cursum > nums[r])
                return false;
            nums[r] -= cursum;
            cursum += nums[r];
            if (r - l + 1 == k)
                cursum -= nums[l++];
        }
        return cursum == 0;
    }
};