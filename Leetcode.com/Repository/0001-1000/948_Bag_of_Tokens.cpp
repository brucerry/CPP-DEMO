// https://leetcode.com/problems/bag-of-tokens/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int res = 0;
        int score = 0;
        for (int l = 0, r = tokens.size() - 1; l <= r; ) {
            if (power >= tokens[l]) {
                power -= tokens[l++];
                res = max(res, ++score);
            }
            else if (score) {
                power += tokens[r--];
                score--;
            }
            else
                break;
        }
        return res;
    }
};