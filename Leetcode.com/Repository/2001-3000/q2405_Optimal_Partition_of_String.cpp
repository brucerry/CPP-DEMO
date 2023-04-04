// https://leetcode.com/problems/optimal-partition-of-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int partitionString(string s) {
        int res = 1, mask = 0;
        for (char c : s) {
            if (mask & (1 << (c - 'a'))) {
                mask = 0;
                res++;
            }
            mask |= 1 << (c - 'a');
        }
        return res;
    }
};