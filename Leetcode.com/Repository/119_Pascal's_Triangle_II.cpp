// https://leetcode.com/problems/pascals-triangle-ii/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> result (rowIndex + 1, 1);

    for (int i = 1; i <= rowIndex; i++) {
      for (int j = i - 1; j >= 1; j--) {
        result[j] += result[j - 1];
      }
    }

    return result;
  }
};