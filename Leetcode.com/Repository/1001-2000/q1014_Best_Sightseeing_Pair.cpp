// https://leetcode.com/problems/best-sightseeing-pair/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int result = 0, prev_best = 0;
    for (const int& value : values) {
      result = max(result, prev_best + value);
      prev_best = max(prev_best, value) - 1;
    }
    return result;
  }
};