// https://leetcode.com/problems/count-pairs-of-similar-strings/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// n = size of words
// w = len of words[i]
// time: O(n * w)
// space: O(n)

class Solution {
public:
  int similarPairs(vector<string>& words) {
    unordered_map<int, int> maskcount; // mask, count
    for (const string& word : words) {
      int mask = 0;
      for (const char& c : word) {
        mask |= 1 << (c - 'a');
      }
      maskcount[mask]++;
    }
    int res = 0;
    for (const auto& [ _, count ] : maskcount) {
      res += count * (count - 1) / 2;
    }
    return res;
  }
};