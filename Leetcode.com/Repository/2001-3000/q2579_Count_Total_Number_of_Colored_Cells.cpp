// https://leetcode.com/problems/count-total-number-of-colored-cells/

// time: O(1)
// space: O(1)

class Solution {
public:
    long long coloredCells(int n) {
        return 1L * n * n + 1L * (n - 1) * (n - 1);
    }
};