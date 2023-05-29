// https://leetcode.com/problems/find-triangular-sum-of-an-array/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while (n > 1) {
            for (int i = 0; i < n - 1; i++) {
                nums[i] = (nums[i] + nums[i+1]) % 10;
            }
            n--;
        }
        return nums[0];
    }
};