// https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/

#include <string>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int prev = -1, count = 0;
            for (int j = i; j < n; j++) {
                int cur = s[j] - '0';
                if (prev == cur) {
                    count++;
                    if (count > 1)
                        break;
                }
                res = max(res, j - i + 1);
                prev = cur;
            }
        }
        return res;
    }
};