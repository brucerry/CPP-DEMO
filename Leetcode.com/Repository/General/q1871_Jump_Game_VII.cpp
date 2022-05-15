// https://leetcode.com/problems/jump-game-vii/

#include <string>
#include <queue>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  bool canReach(string& s, int minJump, int maxJump) {
    int farthestIndex = 0;
    
    queue<int> queue;
    queue.emplace(0);
    while (queue.size()) {
      int i = queue.front();
      queue.pop();
      
      int l = max(i + minJump, farthestIndex + 1);
      int r = min(i + maxJump, (int)s.length() - 1);
      for (int j = l; j <= r; j++) {
        if (s[j] == '0') {
          queue.emplace(j);
          if (j == s.length() - 1)
            return true;
        }
      }
      farthestIndex = i + maxJump;
    }
    
    return false;
  }
};