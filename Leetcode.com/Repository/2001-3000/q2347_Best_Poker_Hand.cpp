// https://leetcode.com/problems/best-poker-hand/

#include <vector>
#include <string>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
  string bestHand(vector<int>& ranks, vector<char>& suits) {
    bool flush = true, three = false, pair = false;
    
    int rankCount[14] = {};
    for (int i = 0; i < 5; i++) {
      if (suits[i] != suits[0])
        flush = false;
      rankCount[ranks[i]]++;
    }
    
    if (flush)
      return "Flush";
    
    for (const int& count : rankCount) {
      if (count >= 2)
        pair = true;
      if (count >= 3)
        three = true;
    }
    
    if (three)
      return "Three of a Kind";
    
    if (pair)
      return "Pair";
    
    return "High Card";
  }
};