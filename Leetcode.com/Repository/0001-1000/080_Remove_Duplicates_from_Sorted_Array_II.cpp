// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;
        for (; r < nums.size(); r++) {
            if (l - 2 < 0 or nums[l-2] != nums[r])
                nums[l++] = nums[r];
        }
        return l;
    }
};