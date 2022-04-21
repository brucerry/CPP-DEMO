// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    char good = 0;
    
    for (const auto& triplet : triplets) {
      if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2])
        continue;
      for (int i = 0; i < 3; i++) {
        if (triplet[i] == target[i])
          good |= (1 << i);
      }
    }
    
    return good == 7;
  }
};