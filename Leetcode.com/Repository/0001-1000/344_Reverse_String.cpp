// https://leetcode.com/problems/reverse-string/

#include <vector>
using namespace std;

// time: O(s)
// space: O(1)
class TwoPointers {
public:
  void reverseString(vector<char>& s) {
    int l = 0, r = s.size() - 1;
    
    while (l < r) {
      swap(s[l], s[r]);
      l++;
      r--;
    }
  }
};

// time: O(s)
// space: O(s)
class Stack {
public:
  void reverseString(vector<char>& s) {
    vector<char> buffer;
    
    for (const char& c : s)
      buffer.emplace_back(c);
    
    for (int i = 0; i < s.size(); i++) {
      s[i] = buffer.back();
      buffer.pop_back();
    }
  }
};

// time: O(s)
// space: O(s)
class Recursive {
public:
  void reverseString(vector<char>& s) {
    solve(s, 0, s.size() - 1);
  }
  
private:
  void solve(vector<char>& s, int left, int right) {
    if (left >= right)
      return;
    
    swap(s[left], s[right]);
    
    solve(s, left + 1, right - 1);
  }
};