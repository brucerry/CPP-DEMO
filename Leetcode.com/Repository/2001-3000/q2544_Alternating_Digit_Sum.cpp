// https://leetcode.com/problems/alternating-digit-sum/

// time: O(log(n))
// space: O(1)

class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0, sign = 1, count = 0;
        while (n) {
            res += n % 10 * sign;
            sign = -sign;
            count++;
            n /= 10;
        }
        return count % 2 ? res : -res;
    }
};