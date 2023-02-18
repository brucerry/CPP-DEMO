// https://leetcode.com/problems/minimum-score-by-changing-two-elements/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min({
            nums[n-3] - nums[0],
            nums[n-1] - nums[2],
            nums[n-2] - nums[1]
        });
    }
};