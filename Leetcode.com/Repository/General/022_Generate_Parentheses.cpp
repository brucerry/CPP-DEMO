// https://leetcode.com/problems/generate-parentheses/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> solution;
    string state;
    solve(n, solution, state, 0, 0);
    return solution;
  }
  
private:
  void solve(int n, vector<string>& solution, string& state, int open, int close) {
    if (n == close) {
      solution.emplace_back(state);
      return;
    }
    
    if (n > open) {
      state += '(';
      solve(n, solution, state, open + 1, close);
      state.pop_back();
    }
    
    if (open > close) {
      state += ')';
      solve(n, solution, state, open, close + 1);
      state.pop_back();
    }
  }
};