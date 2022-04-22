// https://leetcode.com/problems/plus-one/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> ans;
    
    int i = digits.size() - 1, carry = 1;
    
    while (carry || i >= 0) {
      int sum = carry + (i >= 0 ? digits[i] : 0);
      ans.emplace_back(sum % 10);
      carry = sum / 10;
      i--;
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
  }
};