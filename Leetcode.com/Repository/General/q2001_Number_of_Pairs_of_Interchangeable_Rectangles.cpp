// https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    unordered_map<double, long long> ratioCount;
    for (const auto& rect : rectangles) {
      double w = rect[0];
      double h = rect[1];
      ratioCount[w / h]++;
    }
    
    long long result = 0;
    for (auto& [ _, count ] : ratioCount) {
      result += count * (count - 1) / 2;
    }
    
    return result;
  }
};