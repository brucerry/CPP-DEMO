// https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/

#include <string>
using namespace std;

// time: O(n * 2^n)
// space: O(n)

class Solution {
public:
  string minimizeResult(string expression) {
    int n = expression.size(), plus_i = expression.find('+');
    pair<int, int> result { 0, n };
    int curMin = INT_MAX;
    solve(expression, result, curMin, 0, n, plus_i, n);
    expression.insert(result.first, 1, '(');
    expression.insert(result.second + 1, 1, ')');
    return expression;
  }
  
private:
   void solve(string& expr, pair<int, int>& result, int& curMin, int l, int r, int plus_i, int n) {
     if (l == plus_i or r == plus_i + 1)
       return;
     
     int curLeft = stoi(expr.substr(l, plus_i - l));
     int curRight = stoi(expr.substr(plus_i + 1, r - plus_i - 1));
     int multiLeft = l == 0 ? 1 : stoi(expr.substr(0, l));
     int multiRight = r == n ? 1 : stoi(expr.substr(r, n - r));
     int sum = multiLeft * (curLeft + curRight) * multiRight;
     if (sum < curMin) {
       curMin = sum;
       result = { l, r };
     }
     
     solve(expr, result, curMin, l+1, r, plus_i, n);
     solve(expr, result, curMin, l, r-1, plus_i, n);
   }
};