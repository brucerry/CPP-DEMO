// https://leetcode.com/problems/remove-duplicate-letters/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last[26] {};
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        int used[26] {};
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (!used[s[i] - 'a']) {
                while (res.size() and res.back() > s[i] and last[res.back() - 'a'] > i) {
                    used[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                res += s[i];
                used[s[i] - 'a'] = 1;
            }
        }
        return res;
    }
};