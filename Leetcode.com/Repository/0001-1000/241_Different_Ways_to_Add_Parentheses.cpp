// https://leetcode.com/problems/different-ways-to-add-parentheses/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> diffWaysToCompute(string& expression) {
    int n = expression.length();
    vector<int> memo[20][20];
    return solve(expression, memo, 0, expression.length() - 1);
  }
  
private:
  vector<int> solve(string& expression, vector<int> (*memo)[20], int start, int end) {
    if (end - start + 1 < 3)
      return { stoi(expression.substr(start, end - start + 1)) };
    
    if (memo[start][end].size())
      return memo[start][end];
    
    vector<int> result;
    for (int i = start; i <= end; i++) {
      if (expression[i] == '+' or expression[i] == '-' or expression[i] == '*') {
        vector<int> left_result = solve(expression, memo, start, i - 1);
        vector<int> right_result = solve(expression, memo, i + 1, end);
        
        for (const int& left : left_result) {
          for (const int& right : right_result) {
            switch (expression[i]) {
              case '+':
                result.emplace_back(left + right);
                break;
              case '-':
                result.emplace_back(left - right);
                break;
              case '*':
                result.emplace_back(left * right);
                break;
            }
          }
        }
      }
    }
    
    return memo[start][end] = result;
  }
};