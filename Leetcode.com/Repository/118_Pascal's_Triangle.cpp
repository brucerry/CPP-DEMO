// https://leetcode.com/problems/pascals-triangle/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;

    for (int i = 0; i < numRows; i++) {
      vector<int> row (i + 1, 0);
      row[0] = 1;

      if (i > 0) {
        for (int j = 1; j < row.size(); j++) {
          if (j == row.size() - 1) {
            row[j] = 1;
          }
          else {
            row[j] = result[i - 1][j - 1] + result[i - 1][j];
          }
        }
      }

      result.push_back(row);
    }

    return result;
  }
};