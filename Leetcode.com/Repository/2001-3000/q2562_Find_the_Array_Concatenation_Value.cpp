// https://leetcode.com/problems/find-the-array-concatenation-value/

#include <vector>
#include <cmath>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long res = 0;
        for (int l = 0, r = nums.size() - 1; l <= r; l++, r--) {
            if (l == r)
                res += nums[r];
            else
                res += nums[r] + pow(10, (int)log10(nums[r]) + 1) * nums[l];
        }
        return res;
    }
};