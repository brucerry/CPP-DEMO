// https://leetcode.com/problems/multiply-strings/

#include <vector>
#include <string>
using namespace std;

// time: O(n * m)
// space: O(1)

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";
    
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    string ans (num1.length() + num2.length(), '0'); // at most (n + m) length
    
    for (int i = 0; i < num1.length(); i++) { // bottom
        int d1 = num1[i] - '0';
      
      for (int j = 0; j < num2.length(); j++) { // top
        int d2 = num2[j] - '0';
        
        int carry = ans[i + j] - '0';
        int result = d1 * d2 + carry;
        ans[i + j] = result % 10 + '0';
        ans[i + j + 1] += result / 10;
      }
    }
    
    if (ans.back() == '0') // at most 1 leading zero
      ans.pop_back();
    
    reverse(ans.begin(), ans.end());
    
    return ans;
  }
};