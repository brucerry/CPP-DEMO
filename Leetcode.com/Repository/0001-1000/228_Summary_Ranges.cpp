// https://leetcode.com/problems/summary-ranges/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int l = 0, r = 0, n = nums.size();
        while (r < n) {
            while (r + 1 < n and nums[r+1] == nums[r] + 1)
                r++;
            if (l != r)
                res.emplace_back(to_string(nums[l]) + "->" + to_string(nums[r]));
            else
                res.emplace_back(to_string(nums[l]));
            l = r = r + 1;
        }
        return res;
    }
};