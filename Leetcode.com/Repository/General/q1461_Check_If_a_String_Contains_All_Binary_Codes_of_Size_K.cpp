// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

#include <string>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(2^k)

class Solution {
public:
  bool hasAllCodes(string& s, int k) {
    unordered_set<int> codes;
    int code = 0;
    
    for (int i = 0; i < s.length(); i++) {
      code = (code << 1) | (s[i] - '0');
      if (i >= k - 1) {
        codes.insert(code);
        code -= (s[i - (k - 1)] - '0') << (k - 1);
      }
    }
    
    return codes.size() == 1 << k;
  }
};

class Solution {
public:
  bool hasAllCodes(string& s, int k) {
    unordered_set<int> codes;
    int code = 0;
    
    int l = 0;
    for (int r = 0; r < s.length(); r++) {      
      code = (code << 1) | (s[r] - '0');
      if (r - l + 1 == k) {
        codes.insert(code);
        code -= (s[l] - '0') << (k - 1);
        l++;
      }
    }
    
    return codes.size() == 1 << k;
  }
};