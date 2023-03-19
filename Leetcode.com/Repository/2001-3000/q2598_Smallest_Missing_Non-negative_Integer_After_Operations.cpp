// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/

#include <vector>
using namespace std;

// time: O(n)
// space: O(value)

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> counts (value);
        for (int num : nums) {
            counts[(num % value + value) % value]++;
        }
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (--counts[i % value] < 0)
                return i;
        }
        return n;
    }
};