// https://leetcode.com/problems/decode-string/

#include <string>
#include <stack>
using namespace std;

// n = max integer in the range
// m = # of brackets
// time: O(n^m)
// space: O(s)

class Solution {
public:
  string decodeString(string& s) {
    string ans;
    stack<string> stack;

    for (char& ch : s) {
      if ('0' <= ch && ch <= '9') {
        string str = string(1, ch);
        while (stack.size() && '0' <= stack.top()[0] && stack.top()[0] <= '9') {
          str = stack.top() + str;
          stack.pop();
        }
        stack.push(str);
      }
      else if (('a' <= ch && ch <= 'z') || ch == '['){
        stack.push(string(1, ch));
      }
      else {
        string str;
        while (stack.top()[0] != '[') {
          str = stack.top() + str;
          stack.pop();
        }
        stack.pop();
        int num = stoi(stack.top());
        stack.pop();
        string s;
        while (num--) s += str;
        stack.push(s);
      }
    }

    while (stack.size()) {
      ans = stack.top() + ans;
      stack.pop();
    }

    return ans;
  }
};