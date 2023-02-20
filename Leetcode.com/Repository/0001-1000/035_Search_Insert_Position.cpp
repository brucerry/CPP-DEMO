// https://leetcode.com/problems/search-insert-position/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target)
                r = m;
            else
                l = m + 1;
        }
        return r;
    }
};