// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    int scores[100001];
    memset(scores, -1, sizeof(scores));
    
    for (const auto& match : matches) {
      int winner = match[0];
      int loser = match[1];
      if (scores[winner] == -1)
        scores[winner] = 0;
      scores[loser] = scores[loser] == -1 ? 1 : scores[loser] + 1;
    }
    
    vector<vector<int>> result (2);
    for (int i = 1; i <= 100000; i++) {
      if (scores[i] == 0 or scores[i] == 1)
        result[scores[i]].emplace_back(i);
    }
    
    return result;
  }
};