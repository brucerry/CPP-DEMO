// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

#include <string>
#include <vector>
using namespace std;

// time: O(s)
// space: O(1)
class OptimizeSpace {
public:
  int minFlips(string& s) {
    int n = s.length();
    int totalLen = n << 1;
    
    char flip1_l = '0', flip1_r = '0';
    char flip2_l = '1', flip2_r = '1';
    
    int result = n, diff1 = 0, diff2 = 0;
    int l = 0;
    for (int r = 0; r < totalLen; r++) {
      if (flip1_r != s[r % n])
        diff1++;
      if (flip2_r != s[r % n])
        diff2++;
      
      if (r - l + 1 == n) {
        result = min({ result, diff1, diff2 });
        if (flip1_l != s[l])
          diff1--;
        if (flip2_l != s[l])
          diff2--;
        l++;
        flip1_l = flip1_l == '0' ? '1' : '0';
        flip2_l = flip2_l == '0' ? '1' : '0';
      }
      
      flip1_r = flip1_r == '0' ? '1' : '0';
      flip2_r = flip2_r == '0' ? '1' : '0';
    }
    
    return result;
  }
};

// time: O(s)
// space: O(s)
class SubOptimizeSpace {
public:
  int minFlips(string& s) {
    int n = s.length();
    
    s += s;
    
    char flip1_l = '0', flip2_l = '1';
    char flip1_r = '0', flip2_r = '1';
    
    int result = n, diff1 = 0, diff2 = 0;
    int l = 0;
    for (int r = 0; r < s.length(); r++) {
      if (flip1_r != s[r])
        diff1++;
      if (flip2_r != s[r])
        diff2++;
      
      if (r - l + 1 > n) {
        if (flip1_l != s[l])
          diff1--;
        if (flip2_l != s[l])
          diff2--;
        l++;
        flip1_l = flip1_l == '0' ? '1' : '0';
        flip2_l = flip2_l == '0' ? '1' : '0';
      }
      
      if (r - l + 1 == n)
        result = min({ result, diff1, diff2 });
      
      flip1_r = flip1_r == '0' ? '1' : '0';
      flip2_r = flip2_r == '0' ? '1' : '0';
    }
    
    return result;
  }
};

// time: O(s)
// space: O(s)
class Solution {
public:
  int minFlips(string& s) {
    int n = s.length();
    
    s += s;
    
    vector<char> alt1 (s.length());
    vector<char> alt2 (s.length());
    for (int i = 0; i < s.length(); i++) {
      alt1[i] = (i & 1) ? '0' : '1';
      alt2[i] = (i & 1) ? '1' : '0';
    }
    
    int count = n;
    int diff1 = 0, diff2 = 0;
    int l = 0;
    for (int r = 0; r < s.length(); r++) {
      if (s[r] != alt1[r])
        diff1++;
      if (s[r] != alt2[r])
        diff2++;
      
      if (r - l + 1 > n) {
        if (s[l] != alt1[l])
          diff1--;
        if (s[l] != alt2[l])
          diff2--;
        l++;
      }
      
      if (r - l + 1 == n) {
        count = min({ count, diff1, diff2 });
      }
    }
    
    return count;
  }
};