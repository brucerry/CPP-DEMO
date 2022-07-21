// https://leetcode.com/problems/palindrome-partitioning/

#include <vector>
#include <string>
using namespace std;

// time: O(2^n * n)
// space: O(n)

class Solution {
public:
  vector<vector<string>> partition(string& s) {
    vector<vector<string>> solution;
    vector<string> part;
    solve(s, solution, part, 0);
    return solution;
  }
  
private:
  void solve(string& s, vector<vector<string>>& solution, vector<string>& part, int start) {
    if (start == s.length()) {
      solution.emplace_back(part);
      return;
    }
    
    for (int i = start; i < s.length(); i++) {
      if (isPalindrome(s, start, i)) {
        part.emplace_back(s.substr(start, i - start + 1));
        solve(s, solution, part, i + 1);
        part.pop_back();
      }
    }
  }
  
  bool isPalindrome(string& s, int l, int r) {
    for (; l < r; l++, r--) {
      if (s[l] != s[r])
        return false;
    }
    return true;
  }
};