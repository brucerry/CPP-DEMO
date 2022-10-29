// https://leetcode.com/problems/destroy-sequential-targets/

#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int destroyTargets(vector<int>& nums, int space) {
    unordered_map<int, int> umap; // remainder, count
    for (const int& num : nums) {
      umap[num % space]++;
    }

    int result = INT_MAX, destroy = 0;
    for (const int& num : nums) {
      int rmd = num % space;
      if (umap[rmd] > destroy or (umap[rmd] == destroy and num < result)) {
        result = num;
        destroy = umap[rmd];
      }
    }

    return result;
  }
};