// https://leetcode.com/problems/removing-stars-from-a-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class TwoPointers {
public:
  string removeStars(string& s) {
    int j = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '*')
        j--;
      else
        s[j++] = s[i];
    }
    return s.substr(0, j);
  }
};

class Stack {
public:
  string removeStars(string& s) {
    string result;
    for (const char& c : s) {
      if (c == '*')
        result.pop_back();
      else
        result += c;
    }
    return result;
  }
};