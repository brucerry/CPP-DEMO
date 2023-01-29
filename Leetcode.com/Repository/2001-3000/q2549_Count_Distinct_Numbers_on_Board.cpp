// https://leetcode.com/problems/count-distinct-numbers-on-board/

// time: O(1)
// space: O(1)

class Solution {
public:
    int distinctIntegers(int n) {
        return max(1, n - 1);
    }
};