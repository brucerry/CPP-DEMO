// https://leetcode.com/problems/continuous-subarrays/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int range_min = INT_MIN, range_max = INT_MAX;
        long res = 0;
        for (int l = 0, r = 0; r < n; r++) {
            if (range_min <= nums[r] and nums[r] <= range_max) {
                range_min = max(range_min, nums[r] - 2);
                range_max = min(range_max, nums[r] + 2);
            }
            else {
                range_min = nums[r] - 2;
                range_max = nums[r] + 2;
                for (l = r; nums[r] - 2 <= nums[l] and nums[l] <= nums[r] + 2; l--) {
                    range_min = max(range_min, nums[l] - 2);
                    range_max = min(range_max, nums[l] + 2);
                }
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
};