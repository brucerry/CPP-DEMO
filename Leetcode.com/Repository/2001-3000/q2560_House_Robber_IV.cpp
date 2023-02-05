// https://leetcode.com/problems/house-robber-iv/

#include <vector>
using namespace std;

// time: O(n * log(max(nums)))
// space: O(1)

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 1, r = 1e9;
        while (l < r) {
            int m = (l + r) / 2;
            if (canRob(nums, k, m))
                r = m;
            else
                l = m + 1;
        }
        return r;
    }

private:
    bool canRob(vector<int>& nums, int k_houses, int max_amount) {
        int robcount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= max_amount)
                robcount++, i++;
        }
        return robcount >= k_houses;
    }
};