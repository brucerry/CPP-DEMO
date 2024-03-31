// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int lastIndex[2] = { -1, -1 }, validIndex = -1;
        long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK or nums[i] > maxK) {
                lastIndex[0] = lastIndex[1] = validIndex = -1;
                continue;
            }
            if (validIndex == -1)
                validIndex = i;
            if (nums[i] == minK)
                lastIndex[0] = i;
            if (nums[i] == maxK)
                lastIndex[1] = i;
            res += max(0, min(lastIndex[0], lastIndex[1]) - validIndex + 1);
        }
        return res;
    }
};