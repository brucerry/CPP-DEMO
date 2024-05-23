// https://leetcode.com/problems/the-number-of-beautiful-subsets/

#include <vector>
using namespace std;

// time: O(n * 2^n)
// space: O(n)

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        return solve(nums, k, 0, 0);
    }

private:
    int solve(vector<int>& nums, int k, int i, int mask) {
        if (i == nums.size())
            return mask > 0;
        int res = solve(nums, k, i + 1, mask);
        if (canAdd(nums, k, mask, nums[i]))
            res += solve(nums, k, i + 1, mask | (1 << i));
        return res;
    }

    int canAdd(vector<int>& nums, int k, int mask, int num) {
        for (int i = 0; i < nums.size(); i++) {
            if ((mask & (1 << i)) and abs(nums[i] - num) == k)
                return 0;
        }
        return 1;
    }
};