// https://leetcode.com/problems/generate-parentheses/

#include <vector>
#include <string>
using namespace std;

class Solution {
private:
  void solve(vector<string>& ans, string& str, int n, int open, int close) {
    if (close == n) {
      ans.emplace_back(str);
      return;
    }
    
    if (open < n) {
      str += '(';
      solve(ans, str, n, open + 1, close);
      str.pop_back();
    }
    
    if (close < open) {
      str += ')';
      solve(ans, str, n, open, close + 1);
      str.pop_back();
    }
  }
  
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string str;
    solve(ans, str, n, 0, 0);
    return ans;
  }
};