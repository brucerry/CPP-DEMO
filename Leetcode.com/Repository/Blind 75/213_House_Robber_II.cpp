// https://leetcode.com/problems/house-robber-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int res1 = houseRobber(nums, 0, nums.size() - 2);
        int res2 = houseRobber(nums, 1, nums.size() - 1);
        return max({ res1, res2, nums[0] });
    }

private:
    int houseRobber(vector<int>& nums, int l, int r) {
        int rob1 = 0, rob2 = 0;
        for (int i = l; i <= r; i++) {
            int tmp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }
};