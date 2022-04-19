// https://leetcode.com/problems/valid-parentheses/

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, char> map {
      { ')', '(' },
      { ']', '[' },
      { '}', '{' },
    };
    
    vector<char> buffer;
    
    for (const char& ch : s) {
      if (map.count(ch)) {
        if (buffer.size() == 0 || buffer.back() != map[ch])
          return false;
        buffer.pop_back();
      }
      else {
        buffer.emplace_back(ch);
      }
    }
    
    return buffer.size() == 0;
  }
};