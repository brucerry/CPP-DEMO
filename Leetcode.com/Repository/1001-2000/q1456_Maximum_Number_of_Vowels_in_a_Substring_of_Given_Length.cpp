// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

#include <unordered_set>
#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels { 'a', 'e', 'i', 'o', 'u' };

        int res = 0, vowels_count = 0;
        for (int l = 0, r = 0; r < s.size(); r++) {
            vowels_count += vowels.count(s[r]);
            if (r - l + 1 > k) {
                vowels_count -= vowels.count(s[l++]);
            }
            if (r - l + 1 == k) {
                res = max(res, vowels_count);
            }
        }
        return res;
    }
};