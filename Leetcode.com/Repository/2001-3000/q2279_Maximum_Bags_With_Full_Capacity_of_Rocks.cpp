// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int n = rocks.size();
    
    for (int i = 0; i < n; i++) {
      capacity[i] -= rocks[i];
    }
    sort(capacity.begin(), capacity.end());
    
    int full = 0;
    for (const int& empty : capacity) {
      if (additionalRocks >= empty) {
        additionalRocks -= empty;
        full++;
      }
    }
    
    return full;
  }
};