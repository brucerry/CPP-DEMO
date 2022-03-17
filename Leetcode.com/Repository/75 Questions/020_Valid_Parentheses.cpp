// https://leetcode.com/problems/valid-parentheses/

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  bool isValid(string& s) {
    unordered_map<char, char> match {
      {')', '('},
      {'}', '{'},
      {']', '['}
    };

    vector<char> container;

    for (char& ch : s) {
      if (match.count(ch)) {
        if (container.size() == 0 || container.back() != match[ch]) return false;
        container.pop_back();
      }
      else {
        container.emplace_back(ch);
      }
    }

    return container.size() == 0;
  }
};