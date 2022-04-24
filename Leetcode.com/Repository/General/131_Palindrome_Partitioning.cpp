// https://leetcode.com/problems/palindrome-partitioning/

#include <vector>
#include <string>
using namespace std;

// time: O(2^n * n)
// space: O(n)

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> part;
    solve(s, ans, part, 0);
    return ans;
  }
  
private:
  void solve(string& s, vector<vector<string>>& ans, vector<string>& part, int start) {
    if (start == s.length()) {
      ans.emplace_back(part);
      return;
    }
    
    for (int i = start; i < s.length(); i++) {
      if (isPalindrome(s, start, i)) {
        part.emplace_back(s.substr(start, i - start + 1));
        solve(s, ans, part, i + 1);
        part.pop_back();
      }
    }
  }
  
  bool isPalindrome(string& s, int left, int right) {
    for (; left < right; left++, right--) {
      if (s[left] != s[right])
        return false;
    }
    return true;
  }
};