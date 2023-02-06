// https://leetcode.com/problems/shuffle-the-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for (int i = 0; i < n; i++) {
            nums[i] = (nums[i] << 10) | nums[i+n];
        }
        for (int i = n - 1; i >= 0; i--) {
            int xi = nums[i] >> 10;
            int yi = nums[i] & ((1 << 10) - 1);
            nums[i*2+1] = yi;
            nums[i*2] = xi;
        }
        return nums;
    }
};