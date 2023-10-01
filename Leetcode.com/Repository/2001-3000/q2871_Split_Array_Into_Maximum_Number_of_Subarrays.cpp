// https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int zeros = 0;
        int cur = 0;
        for (int num : nums) {
            cur = cur == 0 ? num : cur & num;
            zeros += cur == 0;
        }
        return max(zeros, 1);
    }
};