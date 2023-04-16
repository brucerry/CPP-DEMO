// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/

#include <vector>
#include <string>
#include <cstring>
using namespace std;

// w = size of words
// t = size of target
// n = size of words[i]
// time: O(n * (t + w))
// space: O(t)

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int tsize = target.size(), mod = 1e9 + 7;
        vector<long> dp (tsize + 1);
        dp[0] = 1;
        int count[26];
        for (int i = 0; i < words[0].size(); i++) {
            memset(count, 0, sizeof(count));
            for (string& word : words) {
                count[word[i] - 'a']++;
            }
            for (int j = tsize - 1; j >= 0; j--) {
                dp[j+1] = (dp[j+1] + (dp[j] * count[target[j] - 'a'] % mod)) % mod;
            }
        }
        return dp.back();
    }
};