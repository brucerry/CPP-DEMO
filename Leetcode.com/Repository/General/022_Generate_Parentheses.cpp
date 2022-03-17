/*
  https://leetcode.com/problems/generate-parentheses/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  void generateParenthesis(int n, vector<string>& result, string s, int open, int close) {
    if (close == n) {
      result.push_back(s);
      return;
    }
    if (open < n) {
      generateParenthesis(n, result, s + '(', open + 1, close);
    }
    if (close < open) {
      generateParenthesis(n, result, s + ')', open, close + 1);
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesis(n, result, "", 0, 0);
    return result;
  }
};