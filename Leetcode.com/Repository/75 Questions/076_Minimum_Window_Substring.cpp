// https://leetcode.com/problems/minimum-window-substring/

#include <string>
#include <unordered_map>
using namespace std;

// time: O(s + t)
// space: O(s + t)

class Solution {
public:
  string minWindow(string& s, string& t) {
    if (s.length() < t.length()) return "";
        
    unordered_map<char, int> freq_t, freq_s;

    for (char& ch : t) {
      freq_t[ch]++;
    }

    string ans;
    int left = 0;
    int matched = 0;
    int start = 0;
    int minLen = INT_MAX;

    for (int i = 0; i < s.length(); i++) {
      char ch = s[i];
      freq_s[ch]++;

      if (matched < freq_t.size() && freq_t.count(ch) && freq_s[ch] == freq_t[ch]) {
        matched++;
      }

      if (matched == freq_t.size()) {
        while (freq_t.count(s[left]) == 0 || freq_s[s[left]] > freq_t[s[left]]) {
          freq_s[s[left]]--;
          left++;
        }
        if (i - left < minLen) {
          start = left;
          minLen = i - left + 1;
        }
      }
    }

    return matched == freq_t.size() ? s.substr(start, minLen) : "";
  }
};