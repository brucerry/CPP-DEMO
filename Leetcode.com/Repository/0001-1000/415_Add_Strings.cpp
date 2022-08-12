// https://leetcode.com/problems/add-strings/

#include <string>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  string addStrings(string& num1, string& num2) {
    int len1 = num1.length(), len2 = num2.length(), maxlen = max(len1, len2);
    string result (maxlen + 1, '0');
    
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    int i = 0, carry = 0;
    while (i < maxlen or carry) {
      int d1 = i < len1 ? num1[i] - '0' : 0;
      int d2 = i < len2 ? num2[i] - '0' : 0;
      int sum = d1 + d2 + carry;
      result[i] += sum % 10;
      
      carry = sum / 10;
      i++;
    }
    
    if (result.back() == '0')
      result.pop_back();
    
    reverse(result.begin(), result.end());
    return result;
  }
};