// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// time: O(r * (log(c) + log(k)))
// space: O(k)

class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    set<pair<int, int>> set; // # of soldiers, row index
    for (int r = 0; r < mat.size(); r++) {
      int soldiers = lower_bound(mat[r].begin(), mat[r].end(), 0, greater<>()) - mat[r].begin();
      set.emplace(soldiers, r);
      if (set.size() > k)
        set.erase(--set.end());
    }
    
    vector<int> result;
    for (const auto& [ _, r ] : set){
      result.emplace_back(r);
    }
    
    return result;
  }
};