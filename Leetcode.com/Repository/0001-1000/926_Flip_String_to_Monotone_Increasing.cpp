// https://leetcode.com/problems/flip-string-to-monotone-increasing/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res = 0, ones = 0;
        for (const char& c : s) {
            if (c == '1')
                ones++;
            else
                res = min(res + 1, ones);
        }
        return res;
    }
};