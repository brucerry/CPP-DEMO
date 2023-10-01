// https://leetcode.com/problems/decoded-string-at-index/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long len = 0, i = 0;
        while (len < k) {
            len = isdigit(s[i]) ? len * (s[i] - '0') : len + 1;
            i++;
        }
        while (i--) {
            if (isdigit(s[i])) {
                len /= s[i] - '0';
                k %= len;
            }
            else {
                if (k % len == 0)
                    return string(1, s[i]);
                len--;
            }
        }
        return "";
    }
};