// https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/

// time: O(log(n))
// space: O(1)

class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        while (n) {
            if ((n & 0b11) == 0b11)
                n++, res++;
            else
                res += n & 1, n >>= 1;
        }
        return res;
    }
};