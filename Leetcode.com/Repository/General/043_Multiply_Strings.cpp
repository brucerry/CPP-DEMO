// https://leetcode.com/problems/multiply-strings/

#include <vector>
#include <string>
using namespace std;

// time: O(m * n)
// space: O(1)

class Solution {
public:
  string multiply(string& num1, string& num2) {
    if (num1 == "0" or num2 == "0")
      return "0";
    
    int m = num1.length();
    int n = num2.length();
    
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    string result (m + n, '0'); // at most (n + m) length
    for (int i = 0; i < m; i++) { // bottom
      int d1 = num1[i] - '0';
      
      for (int j = 0; j < n; j++) { // top
        int d2 = num2[j] - '0';
        int product = d1 * d2;
        int sum = result[i + j] - '0' + product;
        result[i + j] = sum % 10 + '0';
        result[i + j + 1] += sum / 10;
      }
    }
    
    if (result.back() == '0') // at most 1 leading zero
      result.pop_back();
    
    reverse(result.begin(), result.end());
    
    return result;
  }
};