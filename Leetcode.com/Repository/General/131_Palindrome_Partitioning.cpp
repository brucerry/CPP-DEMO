// https://leetcode.com/problems/palindrome-partitioning/

#include <vector>
#include <string>
using namespace std;

// time: O(2^n)
// space: O(n)

class Solution {
private:
  bool isPalindrome(string& s, int left, int right) {
    while (left < right) {
      if (s[left] != s[right])
        return false;
      left++;
      right--;
    }
    return true;
  }

  void solve(string& s, vector<vector<string>>& solutions, vector<string>& candidate, int start) {
    if (start == s.length()) {
      solutions.push_back(candidate);
      return;
    }

    for (int i = start; i < s.length(); i++) {
      if (isPalindrome(s, start, i)) {
        candidate.push_back(s.substr(start, i - start + 1));
        solve(s, solutions, candidate, i + 1);
        candidate.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string& s) {
    vector<vector<string>> solutions;
    vector<string> candidate;
    solve(s, solutions, candidate, 0);
    return solutions;
  }
};