// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  string minRemoveToMakeValid(string s) {
    stack<int> stack; // index
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        stack.emplace(i);
      else if (s[i] == ')') {
        if (stack.size())
          stack.pop();
        else
          s[i] = '*';
      }
    }
    while (stack.size()) {
      s[stack.top()] = '*';
      stack.pop();
    }
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;
  }
};