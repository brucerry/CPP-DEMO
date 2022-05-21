// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    char good = 0;
    
    for (const auto& t : triplets) {
      if (t[0] > target[0] or t[1] > target[1] or t[2] > target[2])
        continue;
      for (int i = 0; i < 3; i++) {
        if (t[i] == target[i])
          good |= (1 << i);
      }
    }
    
    return good == 7;
  }
};