// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

#include <vector>
using namespace std;

// time: O(n + log(n) + n * log(max(nums)))
// space: O(log(n)) for sorting

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front();
        while (l < r) {
            int m = (l + r) / 2;
            if (canSolve(nums, p, m))
                r = m;
            else
                l = m + 1;
        }
        return r;
    }

private:
    bool canSolve(vector<int>& nums, int pairs, int diff) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] <= diff) {
                count++;
                i++;
            }
        }
        return count >= pairs;
    }
};