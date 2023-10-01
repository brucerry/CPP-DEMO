// https://leetcode.com/problems/monotonic-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc = 1, dec = 1;
        for (int i = 1; i < nums.size(); i++) {
            inc &= nums[i-1] <= nums[i];
            dec &= nums[i-1] >= nums[i];
        }
        return inc or dec;
    }
};