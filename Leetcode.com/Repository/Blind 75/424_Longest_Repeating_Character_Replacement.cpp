// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <string>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] {};
        int res = 0, max_count = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            max_count = max(max_count, ++count[s[r] - 'A']);
            while (r - l + 1 - max_count > k) {
                count[s[l++] - 'A']--;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};