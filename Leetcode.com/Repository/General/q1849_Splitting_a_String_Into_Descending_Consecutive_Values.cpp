// https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/

#include <string>
using namespace std;

// time: O(s^s) -> pruning to O(s^2)
// space: O(s)

class Solution {
public:
  bool splitString(string& s) {
    for (int i = 0; i < s.length() - 1; i++) {
      unsigned long val = stoul(s.substr(0, i + 1));
      if (searchNext(s, val, i + 1))
        return true;
    }
    return false;
  }
  
private:
  bool searchNext(string& s, unsigned long prev, int start) {
    if (start == s.length())
      return true;
    
    for (int i = start; i < s.length(); i++) {
      unsigned long val = stoul(s.substr(start, i - start + 1));
      if (prev == val + 1 and searchNext(s, val, i + 1))
        return true;
    }
    
    return false;
  }
};