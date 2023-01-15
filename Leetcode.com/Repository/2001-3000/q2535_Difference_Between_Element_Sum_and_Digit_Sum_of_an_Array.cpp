// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/

#include <vector>
using namespace std;

// time: O(n * log(nums[i]))
// space: O(1)

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int res = 0;
        for (int& num : nums) {
            res += num;
            while (num) {
                res -= num % 10;
                num /= 10;
            }
        }
        return res;
    }
};