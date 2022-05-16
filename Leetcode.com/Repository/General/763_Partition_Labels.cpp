// https://leetcode.com/problems/partition-labels/

#include <vector>
#include <string>
#include <array>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  vector<int> partitionLabels(string& s) {
    array<int, 26> charLastIndex;
    for (int i = 0; i < s.length(); i++)
      charLastIndex[s[i] - 'a'] = i;
    
    vector<int> partition;
    int lastIndex = -1;
    int l = 0;
    for (int r = 0; r < s.length(); r++) {
      lastIndex = max(lastIndex, charLastIndex[s[r] - 'a']);
      if (r == lastIndex) {
        partition.emplace_back(r - l + 1);
        l = r + 1;
      }
    }
    
    return partition;
  }
};