// https://leetcode.com/problems/4sum/

#include <algorithm>
#include <vector>
using namespace std;

// time: O(n^3)
// space: O(k)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> state;
        kSum(nums, target, res, state, 0, 4);
        return res;
    }

private:
    void kSum(vector<int>& nums, long target, vector<vector<int>>& res, vector<int>& state, int start, int k) {
        if (k > 2) {
            for (int i = start; i < nums.size() - k + 1; i++) {
                if (i > start and nums[i-1] == nums[i])
                    continue;
                state.emplace_back(nums[i]);
                kSum(nums, target - nums[i], res, state, i + 1, k - 1);
                state.pop_back();
            }
            return;
        }
        int l = start, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum < target)
                l++;
            else if (sum > target)
                r--;
            else {
                state.emplace_back(nums[l]);
                state.emplace_back(nums[r]);
                res.emplace_back(state);
                state.pop_back();
                state.pop_back();
                l++;
                while (l < r and nums[l-1] == nums[l]) {
                    l++;
                }
            }
        }
    }
};