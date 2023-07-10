// https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int res = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > threshold)
                count = 0;
            else {
                if (count)
                    count = nums[i-1] % 2 == nums[i] % 2 ? 0 : count + 1;
                if (count == 0)
                    count = nums[i] % 2 == 0;
            }
            res = max(res, count);
        }
        return res;
    }
};