// https://leetcode.com/problems/number-of-even-and-odd-bits/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0;
        bool even_turn = true;
        while (n) {
            if (even_turn) {
                even += n & 1;
                even_turn = !even_turn;
            }
            else {
                odd += n & 1;
                even_turn = !even_turn;
            }
            n >>= 1;
        }
        return { even, odd };
    }
};