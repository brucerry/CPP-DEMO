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
    array<int, 26> lastIndexOf;
    
    for (int i = 0; i < s.length(); i++) {
      lastIndexOf[s[i] - 'a'] = i;
    }
    
    vector<int> sizeOfParts;
    
    int end = 0;
    int l = 0;
    
    for (int r = 0; r < s.length(); r++) {
      end = max(end, lastIndexOf[s[r] - 'a']);
      
      if (r == end) {
        sizeOfParts.emplace_back(r - l + 1);
        l = r + 1;
      }
    }
    
    return sizeOfParts;
  }
};