// https://leetcode.com/problems/construct-the-longest-new-string/

// time: O(1)
// space: O(1)

class Solution {
public:
    int longestString(int x, int y, int z) {
        return (z + min(x, y) * 2 + (x != y)) * 2;
    }
};