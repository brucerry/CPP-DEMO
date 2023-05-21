// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/

#include <string>
using namespace std;

// time: O(n + m)
// space: O(1)

class Solution {
public:
    int minSteps(string s, string t) {
        int count_s[26] {};
        int count_t[26] {};
        for (char c : s) {
            count_s[c - 'a']++;
        }
        for (char c : t) {
            count_t[c - 'a']++;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += abs(count_s[i] - count_t[i]);
        }
        return res;
    }
};