// https://leetcode.com/problems/shortest-palindrome/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  string shortestPalindrome(string& s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string concated = s + ',' + rev_s;
    
    vector<int> kmp (concated.length());
    for (int i = 1; i < kmp.size(); i++) {
      int j = kmp[i-1];
      while (j and concated[i] != concated[j])
        j = kmp[j-1];
      if (concated[i] == concated[j])
        j++;
      kmp[i] = j;
    }
    
    return rev_s.substr(0, s.length() - kmp.back()) + s;
  }
};