// https://leetcode.com/problems/find-the-value-of-the-partition/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            res = min(res, nums[i] - nums[i-1]);
        }
        return res;
    }
};