// https://leetcode.com/problems/subarray-product-less-than-k/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int curproduct = 1, subarray = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            curproduct *= nums[r];
            while (curproduct >= k and l <= r) {
                curproduct /= nums[l++];
            }
            subarray += r - l + 1;
        }
        return subarray;
    }
};