// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <vector>
#include <string>
#include <stack>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stack;

    for (const string& token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        int a = stack.top();
        stack.pop();
        int b = stack.top();
        stack.pop();
        
        if (token == "+")
          stack.emplace(b + a);
        else if (token == "-")
          stack.emplace(b - a);
        else if (token == "*")
          stack.emplace(b * a);
        else
          stack.emplace(b / a);
      }
      else {
        stack.emplace(stoi(token));
      }
    }

    return stack.top();
  }
};