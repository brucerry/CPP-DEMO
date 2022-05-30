// https://leetcode.com/problems/valid-parentheses/

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool isValid(string& s) {
    unordered_map<char, char> map {
      { ')', '(' },
      { ']', '[' },
      { '}', '{' },
    };
    
    vector<char> buffer;
    for (const char& c : s) {
      if (map.count(c)) {
        if (buffer.size() == 0 or buffer.back() != map[c])
          return false;
        buffer.pop_back();
      }
      else
        buffer.emplace_back(c);
    }
    
    return buffer.size() == 0;
  }
};