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
    for (const char& c : s) {
      if (c != ']') {
        stack.emplace(string(1, c));
      }
      else {
        string letters;
        while (stack.top() != "[") {
          letters.insert(0, stack.top());
          stack.pop();
        }
        
        stack.pop(); // pop "["
        
        string num;
        while (stack.size() and "0" <= stack.top() and stack.top() <= "9") {
          num.insert(0, stack.top());
          stack.pop();
        }
        
        int count = stoi(num);
        string newStr;
        while (count--)
          newStr.append(letters);
        stack.emplace(newStr);
      }
    }
    
    string result;
    while (stack.size()) {
      result.insert(0, stack.top());
      stack.pop();
    }
    
    return result;
  }
};