// https://leetcode.com/problems/jump-game-vii/

#include <string>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool canReach(string& s, int minJump, int maxJump) {
    queue<int> queue; // index
    queue.emplace(0);
    
    int n = s.length();
    int farthestIndex = 0;
    
    while (queue.size()) {
      int cur = queue.front();
      queue.pop();
      
      if (cur == n - 1)
        return true;
      
      int l = max(cur + minJump, farthestIndex + 1);
      int r = min(cur + maxJump, n - 1);
      for (int i = l; i <= r; i++) {
        if (s[i] == '0')
          queue.emplace(i);
      }
      
      farthestIndex = cur + maxJump;
    }
    
    return false;
  }
};