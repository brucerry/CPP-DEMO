// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> umap; // task, count
    for (const int& task : tasks) {
      umap[task]++;
    }
    
    int result = 0;
    for (const auto& [ _, count ] : umap) {
      if (count == 1)
        return -1;
      result += min(ceil(count / 2.0), ceil(count / 3.0));

      // same as
      // result += min((count + 2 - 1) / 2, (count + 3 - 1) / 3);
    }
    return result;
  }
};