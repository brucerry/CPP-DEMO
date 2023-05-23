// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/

#include <string>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size(), res = 0, center = -1;
        for (int l = 0, r = n - 1; l < r; l++, r--) {
            if (s[l] != s[r]) {
                for (int i = r - 1; i >= l + 1; i--) {
                    if (s[i] == s[l]) {
                        for (; i < r; i++) {
                            swap(s[i], s[i+1]);
                            res++;
                        }
                        break;
                    }
                    if (i - 1 == l) { // cannot find the same letter except self
                        center = l;
                        r++; // r can be included in next search
                    }
                }
            }
        }
        if (center != -1)
            res += abs(center - n / 2);
        return res;
    }
};