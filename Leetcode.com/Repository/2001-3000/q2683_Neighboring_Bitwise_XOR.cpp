// https://leetcode.com/problems/neighboring-bitwise-xor/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int res = 0;
        for (int der : derived) {
            res ^= der;
        }
        return res == 0;
    }
};