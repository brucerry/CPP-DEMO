// https://leetcode.com/problems/lexicographically-smallest-palindrome/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        for (int l = 0, r = n - 1; l < r; l++, r--) {
            s[l] = s[r] = min(s[l], s[r]);
        }
        return s;
    }
};