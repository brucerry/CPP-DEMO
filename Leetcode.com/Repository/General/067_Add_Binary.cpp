// https://leetcode.com/problems/add-binary/

#include <string>
using namespace std;

// time: O(max(a, b))
// space: O(1)

class Solution {
public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int maxLen = max(a.length(), b.length()) + 1;
    
    string ans (maxLen, '0');
    
    for (int i = 0; i < maxLen; i++) {
      char bit_a = i < a.length() ? a[i] - '0' : 0;
      char bit_b = i < b.length() ? b[i] - '0' : 0;
      char carry = ans[i] - '0';
      
      int sum = bit_a + bit_b + carry;
      ans[i] = sum % 2 + '0';
      ans[i + 1] = sum / 2 + '0';
    }
    
    if (ans.back() == '0')
      ans.pop_back();
    
    reverse(ans.begin(), ans.end());
    
    return ans;
  }
};