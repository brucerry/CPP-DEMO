// https://leetcode.com/problems/longest-ideal-subsequence/

#include <string>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int cnt[26] {};
        int res = 0;
        for (char c : s) {
            for (int i = c - k; i <= c + k; i++) {
                if ('a' <= i and i <= 'z')
                    cnt[c-'a'] = max(cnt[c-'a'], cnt[i-'a']);
            }
            res = max(res, ++cnt[c-'a']);
        }
        return res;
    }
};