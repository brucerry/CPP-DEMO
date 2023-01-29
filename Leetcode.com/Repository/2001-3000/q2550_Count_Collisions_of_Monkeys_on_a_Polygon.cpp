// https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/

// time: O(log(n))
// space: O(1)

class Solution {
public:
    int monkeyMove(int n) {
        long res = 1, base = 2, mod = 1e9 + 7;
        while (n) {
            if (n % 2)
                res = res * base % mod;
            base = base * base % mod;
            n >>= 1;
        }
        return (res - 2 + mod) % mod;
    }
};