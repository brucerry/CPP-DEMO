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
    
    int result = 0;
    for (int n = tokens.size(), score = 0, l = 0, r = n - 1; l <= r; ) {
      if (power >= tokens[l]) {
        result = max(result, ++score);
        power -= tokens[l++];
      }
      else if (score) {
        score--;
        power += tokens[r--];
      }
      else
        break;
    }
    
    return result;
  }
};