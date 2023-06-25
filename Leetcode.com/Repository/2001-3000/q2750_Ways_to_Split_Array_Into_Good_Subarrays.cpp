// https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int prev = -1;
        long res = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (prev != -1)
                    res = (res * (i - prev)) % 1000000007;
                prev = i;
            }
        }
        return prev == -1 ? 0 : res;
    }
};