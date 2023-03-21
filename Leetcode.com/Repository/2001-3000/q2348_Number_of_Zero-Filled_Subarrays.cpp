// https://leetcode.com/problems/number-of-zero-filled-subarrays/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long res = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            if (nums[r]) {
                l = r + 1;
            }
            res += r - l + 1;
        }
        return res;
    }
};