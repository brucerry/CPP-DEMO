// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <vector>
#include <string>
using namespace std;

// time: O(s)
// space: O(s)

class Solution {
public:
  string removeDuplicates(string& s) {
    vector<char> buffer;
    for (const char& c : s) {
      if (buffer.size() and buffer.back() == c)
        buffer.pop_back();
      else
        buffer.emplace_back(c);
    }
    return string(buffer.begin(), buffer.end());
  }
};