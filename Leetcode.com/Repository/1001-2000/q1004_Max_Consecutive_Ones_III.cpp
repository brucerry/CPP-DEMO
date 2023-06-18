// https://leetcode.com/problems/max-consecutive-ones-iii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0, zeros = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            zeros += nums[r] == 0;
            while (zeros > k) {
                zeros -= nums[l++] == 0;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};