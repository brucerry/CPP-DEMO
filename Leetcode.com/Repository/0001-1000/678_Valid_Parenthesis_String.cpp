// https://leetcode.com/problems/valid-parenthesis-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    bool checkValidString(string s) {
        // open parentheses count in range [minc, maxc]
        int minc = 0, maxc = 0;
        for (char c : s) {
            minc += c == '(' ? 1 : -1;
            maxc += c == ')' ? -1 : 1;
            if (maxc < 0)
                return false;
            minc = max(minc, 0);
        }
        return minc == 0;
    }
};