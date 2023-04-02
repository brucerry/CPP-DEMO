// https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int res = 0, cnt0 = 0, cnt1 = 0;
        for (char c : s) {
            if (c == '0') {
                if (cnt1)
                    cnt0 = cnt1 = 0;
                cnt0++;
            }
            else
                cnt1++;
            res = max(res, min(cnt0, cnt1) * 2);
        }
        return res;
    }
};