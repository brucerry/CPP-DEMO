// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int n = rocks.size();
    
    vector<int> diffs (n);
    for (int i = 0; i < n; i++) {
      diffs[i] = capacity[i] - rocks[i];
    }
    sort(diffs.begin(), diffs.end());
    
    int full = 0;
    for (const int& diff : diffs) {
      if (additionalRocks >= diff) {
        additionalRocks -= diff;
        full++;
      }
    }
    
    return full;
  }
};