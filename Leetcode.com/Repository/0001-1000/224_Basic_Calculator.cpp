// https://leetcode.com/problems/basic-calculator/

#include <string>
#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int calculate(string& s) {
    vector<int> stack;
    int result = 0, curNumber = 0, sign = 1;
    
    for (const char& c : s) {
      if (c >= '0') {
        curNumber = curNumber * 10 + (c - '0');
      }
      else if (c == '+' or c == '-') {
        result += sign * curNumber;
        curNumber = 0;
        sign = c == '+' ? 1 : -1;
      }
      else if (c == '(') {
        stack.emplace_back(result);
        stack.emplace_back(sign);
        result = 0;
        sign = 1;
      }
      else if (c == ')') {
        result += sign * curNumber;
        curNumber = 0;
        result *= stack.back();
        stack.pop_back();
        result += stack.back();
        stack.pop_back();
      }
    }
    
    if (curNumber)
      result += sign * curNumber;
    return result;
  }
};