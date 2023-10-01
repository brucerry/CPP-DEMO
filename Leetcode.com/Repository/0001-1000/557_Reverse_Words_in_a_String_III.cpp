// https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <string>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    string reverseWords(string s) {
        for (int l = 0, r = 0; r <= s.size(); r++) {
            if (s[r] == ' ' or s[r] == 0) {
                reverse(s.begin() + l, s.begin() + r);
                l = r + 1;
            }
        }
        return s;
    }
};