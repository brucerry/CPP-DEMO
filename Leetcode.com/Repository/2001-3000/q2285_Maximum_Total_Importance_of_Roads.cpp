// https://leetcode.com/problems/maximum-total-importance-of-roads/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n) + e)
// space: O(n)

class Solution {
public:
  long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<int> numberOfNeighbors (n);
    for (const auto& road : roads) {
      int u = road[0], v = road[1];
      numberOfNeighbors[u]++;
      numberOfNeighbors[v]++;
    }
    sort(numberOfNeighbors.begin(), numberOfNeighbors.end());

    long result = 0;
    while (n) {
      result += (long)n * numberOfNeighbors[n-1];
      n--;
    }

    return result;
  }
};