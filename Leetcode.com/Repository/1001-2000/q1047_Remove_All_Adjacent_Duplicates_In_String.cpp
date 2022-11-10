// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(n)

class Stack {
public:
  string removeDuplicates(string s) {
    vector<char> stack;
    for (const char& c : s) {
      if (stack.size() and stack.back() == c)
        stack.pop_back();
      else
        stack.emplace_back(c);
    }
    return string(stack.begin(), stack.end());
  }
};

class TwoPointers {
public:
  string removeDuplicates(string s) {
    int end = 0;
    for (int i = 0; i < s.size(); i++, end++) {
      s[end] = s[i];
      if (end and s[end-1] == s[i])
        end -= 2;
    }
    return s.substr(0, end);
  }
};