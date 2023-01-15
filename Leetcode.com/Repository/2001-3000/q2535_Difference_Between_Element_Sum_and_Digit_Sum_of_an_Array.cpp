// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/

#include <vector>
using namespace std;

// time: O(n * log(nums[i]))
// space: O(1)

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int element_sum = 0, digit_sum = 0;
        for (int num : nums) {
            element_sum += num;
            while (num) {
                digit_sum += num % 10;
                num /= 10;
            }
        }
        return abs(element_sum - digit_sum);
    }
};