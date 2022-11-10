// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

#include <string>
#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  string removeDuplicates(string s, int k) {
    vector<pair<char, int>> stack; // char, count
    for (const char& c : s) {
      if (stack.empty() or stack.back().first != c)
        stack.emplace_back(c, 1);
      else if (++stack.back().second == k)
        stack.pop_back();
    }

    string result;
    for (const auto& [ c, count ] : stack)
      result += string(count, c);
    return result;
  }
};

class TwoPointers {
public:
  string removeDuplicates(string s, int k) {
    int end = 0, n = s.size();
    vector<int> counts (n);
    for (int i = 0; i < n; i++, end++) {
      s[end] = s[i];
      counts[end] = end and s[end-1] == s[i] ? counts[end-1] + 1 : 1;
      if (counts[end] == k)
        end -= k;
    }
    return s.substr(0, end);
  }
};