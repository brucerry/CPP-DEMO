// https://leetcode.com/problems/extra-characters-in-a-string/

#include <vector>
#include <string>
using namespace std;

// s = size of s
// d = size of dict
// w = size of dict[i]
// time: O(s * d * w)
// space: O(s)

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp (n + 1);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i+1] + 1;
            for (string& word : dictionary) {
                if (s.compare(i, word.size(), word) == 0) {
                    dp[i] = min(dp[i], dp[i + word.size()]);
                }
            }
        }
        return dp[0];
    }
};