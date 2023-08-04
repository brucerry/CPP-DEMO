// https://leetcode.com/problems/minimum-index-of-a-valid-split/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int maj = 0, maj_freq = 0;
        for (int num : nums) {
            if (maj_freq == 0)
                maj = num;
            maj_freq += maj == num ? 1 : -1;
        }
        maj_freq = 0;
        for (int num : nums) {
            maj_freq += num == maj;
        }
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            count += nums[i] == maj;
            if (count * 2 > i + 1 and (maj_freq - count) * 2 > n - i - 1)
                return i;
        }
        return -1;
    }
};