// https://leetcode.com/problems/partition-labels/

#include <vector>
#include <string>
#include <array>
using namespace std;

// time: O(n)
// space: O(26) => O(1)

class Solution {
public:
  vector<int> partitionLabels(string& s) {
    int n = s.length();

    array<int, 26> charLastIndex;
    for (int i = 0; i < n; i++)
      charLastIndex[s[i] - 'a'] = i;
    
    vector<int> partLens;
    int lastIndex = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
      lastIndex = max(lastIndex, charLastIndex[s[r] - 'a']);
      if (r == lastIndex) {
        partLens.emplace_back(r - l + 1);
        l = r + 1;
      }
    }
    
    return partLens;
  }
};