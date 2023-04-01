// https://leetcode.com/problems/find-the-substring-with-maximum-cost/

#include <string>
#include <vector>
using namespace std;

// time: O(n + m)
// space: O(1)

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int scores[26] = {};
        for (int i = 0; i < 26; i++) {
            scores[i] = i + 1;
        }
        for (int i = 0; i < chars.size(); i++) {
            char c = chars[i];
            int val = vals[i];
            scores[c - 'a'] = val;
        }
        
        int res = 0, cursum = 0;
        for (char c : s) {
            int score = scores[c - 'a'];
            cursum = max(score, cursum + score);
            res = max(res, cursum);
        }
        
        return res;
    }
};