// https://leetcode.com/problems/make-the-string-great/

#include <string>
using namespace std;

// time: O(n)
// space: O(n)
class Stack {
public:
  string makeGood(string s) {
    string good;
    for (const char& c : s) {
      if (good.size() and abs(c - good.back()) == 32)
        good.pop_back();
      else
        good += c;
    }
    return good;
  }
};

// time: O(n)
// space: O(1)
class InPlaceTwoPointers {
public:
  string makeGood(string s) {
    int end = 0;
    for (int i = 0; i < s.size(); i++, end++) {
      s[end] = s[i];
      if (end and abs(s[end-1] - s[i]) == 32)
        end -= 2;
    }
    return s.substr(0, end);
  }
};