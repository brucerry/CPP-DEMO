// https://leetcode.com/problems/buddy-strings/

#include <string>
#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int s_len = s.size();
        int g_len = goal.size();
        
        if (s_len != g_len)
            return false;
        
        if (s == goal) {
            int count[26] {};
            for (char c : s) {
                if (++count[c - 'a'] == 2)
                    return true;
            }
        }

        vector<int> diff;
        for (int i = 0; i < s_len; i++) {
            if (s[i] != goal[i])
                diff.emplace_back(i);
        }

        return diff.size() == 2 and s[diff[0]] == goal[diff[1]] and s[diff[1]] == goal[diff[0]];
    }
};