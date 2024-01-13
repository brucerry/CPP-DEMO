// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] {};
        for (int i = 0; i < s.size(); i++) {
            ++cnt[s[i] - 'a'];
            --cnt[t[i] - 'a'];
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += max(0, cnt[i]);
        }
        return res;
    }
};