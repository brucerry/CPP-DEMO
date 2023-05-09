// https://leetcode.com/problems/valid-anagram/

#include <string>
#include <vector>
using namespace std;

// s = size of s
// t = size of t
// time: O(s + t)
// space: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count_s (26), count_t (26);
        for (char c : s) {
            count_s[c - 'a']++;
        }
        for (char c : t) {
            count_t[c - 'a']++;
        }
        return count_s == count_t;
    }
};