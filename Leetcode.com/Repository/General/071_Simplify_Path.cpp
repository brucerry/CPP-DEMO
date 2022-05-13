// https://leetcode.com/problems/simplify-path/

#include <string>
#include <stack>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  string simplifyPath(string& path) {
    path += '/';
    
    stack<string> stack;
    string cur;
    for (const char& c : path) {
      if (c == '/') {
        if (cur == "..") {
          if (stack.size())
            stack.pop();
        }
        else if (cur.length() and cur != ".") {
          stack.emplace(cur);
        }
        cur = "";
      }
      else
        cur += c;
    }
    
    string result;
    while (stack.size()) {
      result = '/' + stack.top() + result;
      stack.pop();
    }
    
    return result.length() ? result : "/";
  }
};