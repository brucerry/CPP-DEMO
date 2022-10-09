// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

#include <string>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  string robotWithString(string& s) {
    int charCount[26] {};
    for (const char& c : s) {
      charCount[c - 'a']++;
    }

    string result, t;
    int low = 0;
    for (const char& c : s) {
      t += c;
      charCount[c - 'a']--;
      while (low < 26 and charCount[low] == 0)
        low++;
      while (t.size() and t.back() - 'a' <= low) {
        result += t.back();
        t.pop_back();
      }
    }

    return result;
  }
};