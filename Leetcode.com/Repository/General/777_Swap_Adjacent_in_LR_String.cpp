// https://leetcode.com/problems/swap-adjacent-in-lr-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool canTransform(string& start, string& end) {
    int n = start.length();
    
    int s = 0, e = 0;
    while (s < n or e < n) {
      while (s < n and start[s] == 'X')
        s++;
      while (e < n and end[e] == 'X')
        e++;
      
      if (s == n or e == n)
        return s == n and e == n;
      
      if ((start[s] != end[e]) or
          (start[s] == 'L' and s < e) or
          (start[s] == 'R' and s > e))
        return false;
      
      s++;
      e++;
    }
    
    return true;
  }
};