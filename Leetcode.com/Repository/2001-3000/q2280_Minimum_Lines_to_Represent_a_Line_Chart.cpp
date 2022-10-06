// https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  int minimumLines(vector<vector<int>>& stockPrices) {
    int n = stockPrices.size();
    if (n == 1)
      return 0;

    sort(stockPrices.begin(), stockPrices.end());

    int lines = 1;
    for (int i = 2; i < n; i++) {
      int x0 = stockPrices[i-2][0], y0 = stockPrices[i-2][1];
      int x1 = stockPrices[i-1][0], y1 = stockPrices[i-1][1];
      int x2 = stockPrices[i][0], y2 = stockPrices[i][1];
      if (isDifferentSlope(x0, y0, x1, y1, x2, y2))
        lines++;
    }
    return lines;
  }
  
private:
  bool isDifferentSlope(int x0, int y0, int x1, int y1, int x2, int y2) {
    return (long)(y0 - y1) * (x1 - x2) != (long)(y1 - y2) * (x0 - x1);
  }
};