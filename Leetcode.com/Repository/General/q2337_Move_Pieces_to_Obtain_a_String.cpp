// https://leetcode.com/problems/move-pieces-to-obtain-a-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool canChange(string& start, string& target) {
    int n = start.length();
    
    int s = 0, t = 0;
    while (s < n and t < n) {
      while (s < n and start[s] == '_')
        s++;
      while (t < n and target[t] == '_')
        t++;
      
      if (s == n or t == n)
        return s == n and t == n;
      
      if ((start[s] != target[t]) or
          (start[s] == 'L' and s < t) or
          (start[s] == 'R' and s > t))
        return false;
      
      s++;
      t++;
    }
    
    return true;
  }
};