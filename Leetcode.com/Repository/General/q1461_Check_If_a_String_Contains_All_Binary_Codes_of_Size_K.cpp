// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

#include <string>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(2^k)

class Solution {
public:
  bool hasAllCodes(string& s, int k) {
    unordered_set<int> codeSet;
    int val = 0;
    
    for (int i = 0; i < s.length(); i++) {
      val = (val << 1) | (s[i] - '0');
      if (i >= k - 1) {
        codeSet.insert(val);
        val -= (s[i - (k - 1)] - '0') << (k - 1);
      }
    }
    
    return codeSet.size() == 1 << k;
  }
};