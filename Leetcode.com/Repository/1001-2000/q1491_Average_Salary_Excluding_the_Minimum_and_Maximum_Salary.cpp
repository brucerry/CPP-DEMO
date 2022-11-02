// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  double average(vector<int>& salary) {
    int minNum = 1e9, maxNum = 0;
    double sum = 0;
    for (const int& s : salary) {
      sum += s;
      minNum = min(minNum, s);
      maxNum = max(maxNum, s);
    }
    return (sum - minNum - maxNum) / (salary.size() - 2);
  }
};