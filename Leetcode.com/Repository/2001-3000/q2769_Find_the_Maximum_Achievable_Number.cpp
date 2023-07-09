// https://leetcode.com/problems/find-the-maximum-achievable-number/

// time: O(1)
// space: O(1)

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2 * t;
    }
};