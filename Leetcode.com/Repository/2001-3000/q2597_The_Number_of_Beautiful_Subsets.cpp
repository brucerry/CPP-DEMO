// https://leetcode.com/problems/the-number-of-beautiful-subsets/

#include <vector>
using namespace std;

// time: O(n * 2^n)
// space: O(n)

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int res = 0;
        solve(nums, k, 0, res, 0);
        return res;
    }

private: 
    void solve(vector<int>& nums, int k, int mask, int& res, int i) {
        if (i == nums.size()) {
            res += mask > 0;
            return;
        }
        
        solve(nums, k, mask, res, i + 1);
        if (canAdd(nums, mask, nums[i], k)) {
            solve(nums, k, mask | (1 << i), res, i + 1);
        }
    }
   
    bool canAdd(vector<int>& nums, int mask, int num, int k) {
        for (int i = 0; i < nums.size(); i++) {
            if ((mask & (1 << i)) and abs(num - nums[i]) == k)
                return false;
        }
        return true;
    }
};