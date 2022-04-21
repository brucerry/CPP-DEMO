// https://leetcode.com/problems/partition-labels/

#include <vector>
#include <string>
#include <array>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  vector<int> partitionLabels(string s) {
    array<int, 26> lastIndex;
    
    for (int i = 0; i < s.length(); i++) {
      lastIndex[s[i] - 'a'] = i;
    }
    
    int size = 0, end = 0;
    vector<int> ans;
    
    for (int i = 0; i < s.length(); i++) {
      size++;
      end = max(end, lastIndex[s[i] - 'a']);
      
      if (i == end) {
        ans.emplace_back(size);
        size = 0;
      }
    }
    
    return ans;
  }
};