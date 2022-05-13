// https://leetcode.com/problems/implement-strstr/

#include <string>
#include <vector>
using namespace std;

// n = len of haystack
// m = len of needle
// time: O(n * m)
// space: O(1)
class Solution {
public:
  int strStr(string& haystack, string& needle) {
    int n = haystack.length();
    int m = needle.length();
    
    for (int i = 0; i < n - m + 1; i++) {
      for (int j = 0; j < m; j++) {
        if (haystack[i + j] != needle[j])
          break;
        if (j + 1 == m)
          return i;
      }
    }
    
    return -1;
  }
};

// n = len of haystack
// m = len of needle
// time: O(n + m)
// space: O(m)
class Solution {
public:
  int strStr(string& haystack, string& needle) {
    int n = haystack.length();
    int m = needle.length();
    
    vector<int> lps (m); // longest prefix suffix
    int prevLPS = 0, i = 1;
    while (i < m) {
      if (needle[i] == needle[prevLPS]) {
        lps[i] = prevLPS + 1;
        prevLPS++;
        i++;
      }
      else if (prevLPS == 0) {
        lps[i] = 0;
        i++;
      }
      else {
        prevLPS = lps[prevLPS - 1];
      }
    }
    
    int j = 0, k = 0;
    while (j < n) {
      if (haystack[j] == needle[k]) {
        j++;
        k++;
      }
      else if (k == 0) {
        j++;
      }
      else {
        k = lps[k - 1];
      }
      
      if (k == m)
        return j - m;
    }
    
    return -1;
  }
};