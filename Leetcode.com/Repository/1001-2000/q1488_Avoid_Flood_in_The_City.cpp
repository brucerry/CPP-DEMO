// https://leetcode.com/problems/avoid-flood-in-the-city/

#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  vector<int> avoidFlood(vector<int>& rains) {    
    unordered_map<int, int> lakeIndex; // lake, index
    set<int> dryIndex; // index

    vector<int> result;
    for (int i = 0; i < rains.size(); i++) {
      int lake = rains[i];
      if (!lake) {
        dryIndex.insert(i);
        result.emplace_back(1);
      }
      else {
        if (lakeIndex.count(lake)) {
          int idx = lakeIndex[lake];
          auto it = dryIndex.lower_bound(idx);
          if (it == dryIndex.end())
            return {};
          result[*it] = lake;
          dryIndex.erase(it);
        }
        lakeIndex[lake] = i;
        result.emplace_back(-1);
      }
    }
    
    return result;
  }
};