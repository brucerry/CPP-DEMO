// https://leetcode.com/problems/divide-chocolate/

#include <vector>
using namespace std;

// s = sum of sweetness
// time: O(n * log(s))
// space: O(1)

class Solution {
public:
  int maximizeSweetness(vector<int>& sweetness, int k) {
    int l = INT_MAX, r = 0;
    for (const int& swt : sweetness) {
      l = min(l, swt);
      r += swt;
    }

    while (l < r) {
      int m = l + ((r - l) >> 1);
      if (canSplit(sweetness, k + 1, m))
        l = m + 1;
      else
        r = m;
    }
    return l - 1;
  }

private:
  bool canSplit(vector<int>& sweetness, int group, int splitMin) {
    int subarray = 0, curSum = 0;
    for (const int& swt : sweetness) {
      curSum += swt;
      if (curSum >= splitMin) {
        curSum = 0;
        subarray++;
      }
    }
    return subarray >= group;
  }
};