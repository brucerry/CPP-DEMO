// https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> count (n, -1);
        count[0] = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] == -1)
                continue;
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[j] - nums[i]) <= target) {
                    count[j] = max(count[j], count[i] + 1);
                }
            }
        }
        return count[n-1];
    }
};