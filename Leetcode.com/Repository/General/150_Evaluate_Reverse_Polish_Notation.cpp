// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    vector<int> buffer;
    
    for (const string& token : tokens) {
      if (token == "+" or token == "-" or token == "*" or token == "/") {
        int a = buffer.back();
        buffer.pop_back();
        int b = buffer.back();
        buffer.pop_back();
        
        if (token == "+")
          buffer.emplace_back(a + b);
        else if (token == "-")
          buffer.emplace_back(b - a);
        else if (token == "*")
          buffer.emplace_back(a * b);
        else
          buffer.emplace_back(b / a);
      }
      else
        buffer.emplace_back(stoi(token));
    }
    
    return buffer[0];
  }
};