// https://leetcode.com/problems/minimize-string-length/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int minimizedStringLength(string s) {
        int mask = 0;
        for (char c : s) {
            mask |= 1 << (c - 'a');
        }
        return __builtin_popcount(mask);
    }
};