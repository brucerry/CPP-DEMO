// https://leetcode.com/problems/rank-transform-of-an-array/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    int n = arr.size();
    
    vector<pair<int, int>> sorted (n); // value, index
    for (int i = 0; i < n; i++) {
      sorted[i] = { arr[i], i };
    }
    sort(sorted.begin(), sorted.end());
    
    int rank = 0, prev = INT_MIN;
    for (const auto& [ value, i ] : sorted) {
      if (prev < value)
        rank++;
      arr[i] = rank;
      prev = value;
    }
    
    return arr;
  }
};