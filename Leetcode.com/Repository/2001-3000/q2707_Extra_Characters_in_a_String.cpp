// https://leetcode.com/problems/extra-characters-in-a-string/

#include <vector>
#include <string>
using namespace std;

// s = size of s
// d = size of dict
// w = size of dict[i]
// time: O(s * s * d * w)
// space: O(s)

class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        vector<int> memo (n);
        int max_match = solve(s, dict, memo, 0);
        return n - max_match;
    }

private:
    int solve(string& s, vector<string>& dict, vector<int>& memo, int start) {
        if (start >= s.size())
            return 0;
        
        int& res = memo[start];
        if (res)
            return res;
        
        for (int i = start; i < s.size(); i++) {
            for (string& word : dict) {
                if (s.compare(i, word.size(), word) == 0) {
                    res = max(res, (int)word.size() + solve(s, dict, memo, i + word.size()));
                }
            }
        }
        
        return res;
    }
};