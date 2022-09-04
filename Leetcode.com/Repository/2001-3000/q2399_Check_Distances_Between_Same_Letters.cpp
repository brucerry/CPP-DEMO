// https://leetcode.com/problems/check-distances-between-same-letters/

#include <string>
#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool checkDistances(string& s, vector<int>& distance) {
    int pos[26] {};
    for (int i = 0; i < s.length(); i++) {
      int j = s[i] - 'a';
      if (pos[j] and i - pos[j] != distance[j])
        return false;
      pos[j] = i + 1;
    }
    return true;
  }
};