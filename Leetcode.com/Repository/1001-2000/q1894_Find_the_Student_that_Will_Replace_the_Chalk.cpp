// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int chalkReplacer(vector<int>& chalk, int k) {
    long sum = accumulate(chalk.begin(), chalk.end(), 0L);
    k %= sum;
    for (int i = 0; i < chalk.size(); i++) {
      if (k < chalk[i])
        return i;
      k -= chalk[i];
    }
    return 0;
  }
};