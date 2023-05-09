// https://leetcode.com/problems/permutation-in-string/

#include <string>
#include <vector>
using namespace std;

// s1 = size of s1
// s2 = size of s2
// time: O(s1 + s2)
// space: O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count_s1 (26), count_s2 (26);
        for (char c : s1) {
            count_s1[c - 'a']++;
        }
        for (int l = 0, r = 0; r < s2.size(); r++) {
            count_s2[s2[r] - 'a']++;
            if (r - l + 1 > s1.size()) {
                count_s2[s2[l] - 'a']--;
                l++;
            }
            if (count_s1 == count_s2)
                return true;
        }
        return false;
    }
};