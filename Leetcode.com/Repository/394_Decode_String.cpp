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
    stack<string> stack;

    for (char& ch : s) {
      if (ch != ']') {
        stack.push(string(1, ch));
      }
      else {
        string str;
        while (stack.top() != "[") {
          str = stack.top() + str;
          stack.pop();
        }
        stack.pop(); // pop the "["

        string num;
        while (stack.size() && "0" <= stack.top() && stack.top() <= "9") {
          num = stack.top() + num;
          stack.pop();
        }

        int inum = stoi(num);
        string repeatedStr;
        while (inum--) repeatedStr += str;
        stack.push(repeatedStr);
      }
    }

    string ans;
    while (stack.size()) {
      ans = stack.top() + ans;
      stack.pop();
    }

    return ans;
  }
};