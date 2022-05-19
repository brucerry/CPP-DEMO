// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

#include <string>
#include <unordered_map>
using namespace std;

// time: O((2^s)^2)
// space: O(2^s)

class Solution {
public:
  int maxProduct(string& s) {
    int n = s.length();
    int all = (1 << n) - 1;
    
    unordered_map<int, int> palinLen; // mask, len
    for (int mask = 1; mask <= all; mask++) {
      string subseq;
      
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i))
          subseq += s[i];
      }
      
      if (isPalidrome(subseq))
        palinLen[mask] = subseq.length();
    }
    
    int maxProduct = 0;
    for (const auto& [ mask1, len1 ] : palinLen) {
      for (const auto& [ mask2, len2 ] : palinLen) {
        if ((mask1 & mask2) == 0)
          maxProduct = max(maxProduct, len1 * len2);
      }
    }
    
    return maxProduct;
  }
  
private:
  bool isPalidrome(string& s) {
    for (int l = 0, r = s.length() - 1; l < r; l++, r--) {
      if (s[l] != s[r])
        return false;
    }
    return true;
  }
};