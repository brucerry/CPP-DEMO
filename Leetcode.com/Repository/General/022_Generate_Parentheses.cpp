// https://leetcode.com/problems/generate-parentheses/

#include <vector>
#include <string>
using namespace std;

class Solution {
private:
  void solve(vector<string>& ans, string& comb, int n, int open, int close) {
    if (close == n) {
      ans.emplace_back(comb);
      return;
    }
    
    if (open < n) {
      comb += '(';
      solve(ans, comb, n, open + 1, close);
      comb.pop_back();
    }
    
    if (close < open) {
      comb += ')';
      solve(ans, comb, n, open, close + 1);
      comb.pop_back();
    }
  }
  
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string comb;
    solve(ans, comb, n, 0, 0);
    return ans;
  }
};