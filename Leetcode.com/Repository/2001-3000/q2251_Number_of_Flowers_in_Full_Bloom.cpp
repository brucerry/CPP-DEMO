// https://leetcode.com/problems/number-of-flowers-in-full-bloom/

#include <vector>
#include <algorithm>
using namespace std;

// f = size of flowers
// p = size of persons
// time: O(f * log(f) + p * log(p) + p * log(f))
// space: O(f)

class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
    vector<int> starts, ends;
    for (const auto& flo : flowers) {
      starts.emplace_back(flo[0]);
      ends.emplace_back(flo[1]);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    vector<int> result;
    for (const int& time: persons) {
      int started = upper_bound(starts.begin(), starts.end(), time) - starts.begin();
      int ended = lower_bound(ends.begin(), ends.end(), time) - ends.begin();
      result.emplace_back(started - ended);
    }

    return result;
  }
};