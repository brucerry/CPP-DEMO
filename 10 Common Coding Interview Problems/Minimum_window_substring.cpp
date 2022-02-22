/*
  s = length of s
  t = length of t

  time: O(s + t)
  space: O(s + t)
*/

#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

string minWindow(string& s, string& t) {
  int len_s = s.length();
  int len_t = t.length();
  if (len_s < len_t || len_t == 0) return "";

  unordered_map<char, int> freq_t;
  for (char& ch : t) {
    freq_t[ch]++;
  }

  int satisfied = 0;
  int start = 0;
  int end = len_s - 1;

  unordered_map<char, int> freq_s;
  int left = 0;
  int right = 0;
  while (right < len_s) {
    char ch = s[right];
    freq_s[ch]++;

    if (satisfied < freq_t.size() && freq_t.count(ch) && freq_t[ch] == freq_s[ch]) {
      satisfied++;
    }

    if (satisfied == freq_t.size()) {
      while (left < right) {
        if (freq_t.count(s[left]) == 0 || freq_s[s[left]] > freq_t[s[left]]) {
          freq_s[s[left]]--;
          left++;
        } else {
          break;
        }
      }
      if (right - left < end - start) {
        start = left;
        end = right;
      }
    }

    right++;
  }

  return satisfied == freq_t.size() ? s.substr(start, end - start + 1) : "";
}

int main() {
  string s = "abcfebeceabebadfcdfcbfcbead";
  string t = "abca";
  // string s = "fffffffffffffffffffff";
  // string t = "abca";
  cout << minWindow(s, t);
}