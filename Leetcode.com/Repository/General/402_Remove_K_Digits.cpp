// https://leetcode.com/problems/remove-k-digits/

#include <string>
#include <vector>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  string removeKdigits(string& num, int k) {
    string result;
    for (const char& c : num) {
      while (result.length() and result.back() > c and k) {
        result.pop_back();
        k--;
      }
      result += c;
    }
    
    int i = 0;
    while (i < result.length() and result[i] == '0')
      i++;
    
    while (k-- and result.length())
      result.pop_back();
    
    return i < result.length() ? result.substr(i) : "0";
  }
};