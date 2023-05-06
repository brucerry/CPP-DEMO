// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int min_i = -1, min_num = nums.back();
        int max_i = -2, max_num = nums.front();
        for (int i = 1; i < n; i++) {
            max_num = max(max_num, nums[i]);
            min_num = min(min_num, nums[n-1-i]);
            if (nums[i] < max_num)
                max_i = i;
            if (nums[n-1-i] > min_num)
                min_i = n - 1 - i;
        }
        return max_i - min_i + 1;
    }
};