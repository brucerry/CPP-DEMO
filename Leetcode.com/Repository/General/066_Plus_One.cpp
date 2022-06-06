// https://leetcode.com/problems/plus-one/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    
    reverse(digits.begin(), digits.end());
    digits.emplace_back(0);
    digits[0] = 1;
    
    for (int i = 0; i < n; i++) {
      int sum = digits[i];
      digits[i] = sum % 10;
      digits[i+1] += sum / 10;
    }
    
    if (digits.back() == 0)
      digits.pop_back();
    
    reverse(digits.begin(), digits.end());
    return digits;
  }
};