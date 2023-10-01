// https://leetcode.com/problems/sort-array-by-parity/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int l = 0, r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 == 0)
                swap(nums[l++], nums[r]);
        }
        return nums;
    }
};