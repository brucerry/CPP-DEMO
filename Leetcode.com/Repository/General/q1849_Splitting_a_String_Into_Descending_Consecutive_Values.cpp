// https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/

#include <string>
using namespace std;

// time: O(s^s)
// space: O(s)

class Solution {
public:
  bool splitString(string& s) {
    for (int i = 0; i < s.length() - 1; i++) {
      unsigned long long val = stoull(s.substr(0, i + 1));
      if (searchNext(s, i + 1, val))
        return true;
    }
    return false;
  }
  
private:
  bool searchNext(string& s, int start, unsigned long long prev) {
    if (start == s.length())
      return true;
    
    for (int i = start; i < s.length(); i++) {
      unsigned long long val = stoull(s.substr(start, i - start + 1));
      if (val + 1 == prev and searchNext(s, i + 1, val))
        return true;
    }
    
    return false;
  }
};