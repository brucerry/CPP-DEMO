// https://leetcode.com/problems/maximum-number-of-removable-characters/

#include <vector>
#include <string>
using namespace std;

// s = len of s
// n = size of removable
// time: O(s * log(n))
// space: O(s)

class Solution {
public:
  int maximumRemovals(string& s, string& p, vector<int>& removable) {
    vector<int> sMap (s.length(), INT_MAX);
    for (int i = 0; i < removable.size(); i++) {
      sMap[removable[i]] = i;
    }
    
    int l = 0, r = removable.size();
    while (l < r) {
      int m = l + ((r - l + 1) >> 1);
      if (canRemove(s, p, sMap, m))
        l = m;
      else
        r = m - 1;
    }
    return l;
  }
  
private:
  bool canRemove(string& s, string& p, vector<int>& sMap, int removeCount) {
    int j = 0;
    for (int i = 0; i < s.length() and j < p.length(); i++) {
      if (s[i] == p[j] and sMap[i] >= removeCount)
        j++;
    }
    return j == p.length();
  }
};