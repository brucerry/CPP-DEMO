// https://leetcode.com/problems/jump-game-vii/

#include <string>
#include <queue>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  bool canReach(string& s, int minJump, int maxJump) {
    queue<int> queue; // index
    queue.emplace(0);
    
    int farthestIndex = 0;
    
    while (queue.size()) {
      int cur = queue.front();
      queue.pop();
      
      int l = max(cur + minJump, farthestIndex + 1);
      int r = min(cur + maxJump, (int)s.length() - 1);
      for (int i = l; i <= r; i++) {
        if (s[i] == '0') {
          if (i == s.length() - 1)
            return true;
          queue.emplace(i);
        }
      }
      
      farthestIndex = cur + maxJump;
    }
    
    return false;
  }
};