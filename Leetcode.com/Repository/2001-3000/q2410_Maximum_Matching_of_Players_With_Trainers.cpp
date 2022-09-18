// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/

#include <vector>
#include <algorithm>
using namespace std;

// p = size of players
// t = size of trainers
// time: O(p * log(p) + t * log(t))
// space: O(log(p) + log(t)) for sorting

class Solution {
public:
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());
    
    int result = 0;
    for (int p = 0, t = 0; p < players.size() and t < trainers.size(); t++) {
      if (players[p] <= trainers[t]) {
        p++;
        result++;
      }
    }
    
    return result;
  }
};