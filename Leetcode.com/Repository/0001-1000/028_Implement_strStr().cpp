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

// KnuthMorrisPratt
// n = len of haystack
// m = len of needle
// time: O(n + m)
// space: O(m)
class KMP {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        vector<int> preproc (n);
        kmpPreprocess(needle, preproc);

        int i = 0, j = 0;
        while (i < m and j < n) {
            if (haystack[i] == needle[j]) {
                i++, j++;
            }
            else if (j) {
                j = preproc[j-1];
            }
            else {
                i++;
            }
        }
        return j == n ? i - j : -1;
    }

private:
    void kmpPreprocess(string& needle, vector<int>& preproc) {
        int l = 0, r = 1;
        while (r < needle.size()) {
            if (needle[l] == needle[r]) {
                preproc[r] = l + 1;
                l++, r++;
            }
            else if (l) {
                l = preproc[l-1];
            }
            else {
                r++;
            }
        }
    }
};