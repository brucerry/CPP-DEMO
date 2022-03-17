// https://leetcode.com/problems/add-binary/

#include <string>
using namespace std;

// time: O(max(a, b))
// space: O(1)

class Solution {
public:
  string addBinary(string& a, string& b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int carry = 0;
    const int maxLen = max(a.length(), b.length());
    string ans;

    for (int i = 0; i < maxLen; i++) {
      int digitA = i < a.length() ? a[i] - '0' : 0;
      int digitB = i < b.length() ? b[i] - '0' : 0;
      int total = digitA + digitB + carry;
      
      char ch = (total % 2) + '0';
      ans = ch + ans;

      carry = total >> 1;
    }

    if (carry) {
      ans = '1' + ans;
    }

    return ans;
  }
};