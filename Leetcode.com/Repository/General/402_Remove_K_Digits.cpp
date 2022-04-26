// https://leetcode.com/problems/remove-k-digits/

#include <string>
#include <vector>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  string removeKdigits(string& num, int k) {
    string ans;
    
    for (const char& n : num) {
      while (k and ans.length() and ans.back() > n) {
        ans.pop_back();
        k--;
      }
      ans += n;
    }
    
    int i = 0;
    while (i < ans.length() and ans[i] == '0') {
      i++;
    }
    
    while (k-- and ans.length()) {
      ans.pop_back();
    }
    
    return i < ans.length() ? ans.substr(i) : "0";
  }
};