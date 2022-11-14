// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size(), groups = 0;
    unordered_map<int, int> parents;
    for (int i = 0; i < n; i++) {
      uni(parents, groups, stones[i][0], ~stones[i][1]);
    }
    return n - groups;
  }

private:
  void uni(unordered_map<int, int>& parents, int& groups, int x, int y) {
    x = find(parents, groups, x);
    y = find(parents, groups, y);
    if (x != y) {
      parents[x] = y;
      groups--;
    }
  }

  int find(unordered_map<int, int>& parents, int& groups, int p) {
    if (parents.count(p) == 0) {
      parents[p] = p;
      groups++;
    }
    if (p != parents[p])
      parents[p] = find(parents, groups, parents[p]);
    return parents[p];
  }
};