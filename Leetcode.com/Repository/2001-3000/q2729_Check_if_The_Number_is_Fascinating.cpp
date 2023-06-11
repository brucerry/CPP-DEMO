// https://leetcode.com/problems/check-if-the-number-is-fascinating/

// time: O(1)
// space: O(1)

class Solution {
public:
    bool isFascinating(int n) {
        int count[10] {};
        for (int i = 1; i <= 3; i++) {
            int val = n * i;
            while (val) {
                count[val % 10]++;
                val /= 10;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (count[0] or count[i] > 1)
                return false;
        }
        return true;
    }
};