// https://leetcode.com/problems/squares-of-a-sorted-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res (n);
        for (int i = n - 1, l = 0, r = n - 1; i >= 0; i--) {
            if (abs(nums[l]) > abs(nums[r]))
                res[i] = nums[l] * nums[l], l++;
            else
                res[i] = nums[r] * nums[r], r--;
        }
        return res;
    }
};