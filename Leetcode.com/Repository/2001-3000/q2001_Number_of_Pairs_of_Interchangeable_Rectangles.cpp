// https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    unordered_map<double, int> ratioCount; // ratio, count
    for (const auto& rect : rectangles) {
      double w = rect[0];
      double h = rect[1];
      ratioCount[w/h]++;
    }
    
    long long pair = 0;
    for (const auto& [ _, count ] : ratioCount) {
      pair += ((long long)count * (count - 1)) >> 1;
    }
    return pair;
  }
};