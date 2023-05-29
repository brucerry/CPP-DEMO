// https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size(), del = 0;
        int l = 0, r = 0;
        for (; r < n; r++) {
            if (nums[l] != nums[r]) {
                del += r - l - 1;
                l = r + 1;
            }
        }
        return del + (r - l);
    }
};