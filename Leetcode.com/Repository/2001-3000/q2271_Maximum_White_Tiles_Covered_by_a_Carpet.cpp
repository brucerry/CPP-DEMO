// https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
    sort(tiles.begin(), tiles.end());

    int result = 0;
    for (int t = 0, i = 0, n = tiles.size(), totallyCovered = 0; t < n and i < n; ) {
      if (tiles[i][0] + carpetLen - 1 >= tiles[t][1]) {
        totallyCovered += tiles[t][1] - tiles[t][0] + 1;
        result = max(result, totallyCovered);
        t++;
      }
      else {
        int partiallyCovered = max(0, (tiles[i][0] + carpetLen - 1) - tiles[t][0] + 1);
        result = max(result, totallyCovered + partiallyCovered);
        totallyCovered -= tiles[i][1] - tiles[i][0] + 1;
        i++;
      }
    }
    return result;
  }
};