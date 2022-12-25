// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/

#include <vector>
#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int closetTarget(vector<string>& words, string target, int startIndex) {
    int res = INT_MAX, n = words.size();
    for (int i = 0; i < n; i++) {
      if (target == words[i]) {
        int dist = abs(i - startIndex);
        res = min({ res, dist, n - dist });
      }
    }
    return res == INT_MAX ? -1 : res;
  }
};