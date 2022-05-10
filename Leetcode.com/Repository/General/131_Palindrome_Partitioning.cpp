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
    vector<string> state;
    solve(s, solution, state, 0);
    return solution;
  }
  
private:
  void solve(string& s, vector<vector<string>>& solution, vector<string>& state, int start) {
    if (start == s.length()) {
      solution.emplace_back(state);
      return;
    }
    
    for (int i = start; i < s.length(); i++) {
      if (isPalindrome(s, start, i)) {
        state.emplace_back(s.substr(start, i - start + 1));
        solve(s, solution, state, i + 1);
        state.pop_back();
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