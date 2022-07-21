// https://leetcode.com/problems/count-number-of-texts/

#include <string>
#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class SpaceOptimizedDP {
public:
  int countTexts(string& pressedKeys) {
    int n = pressedKeys.size();
    vector<int> dp (5);
    dp[n % 5] = 1;
    
    for (int i = n - 1; i >= 0; i--) {
      dp[i % 5] = 0;
      char key = pressedKeys[i];
      int maxlen = key == '7' or key == '9' ? 4 : 3;
      for (int j = i + 1; j <= min(i + maxlen, n); j++) {
        dp[i % 5] += dp[j % 5];
        dp[i % 5] %= 1000000007;
        if (key != pressedKeys[j])
          break;
      }
    }
    
    return dp[0];
  }
};

// time: O(n)
// space: O(n)
class DP {
public:
  int countTexts(string& pressedKeys) {
    int n = pressedKeys.size();
    vector<int> dp (n + 1);
    dp.back() = 1;
    
    for (int i = n - 1; i >= 0; i--) {
      char key = pressedKeys[i];
      int maxlen = key == '7' or key == '9' ? 4 : 3;
      for (int j = i + 1; j <= min(i + maxlen, n); j++) {
        dp[i] += dp[j];
        dp[i] %= 1000000007;
        if (key != pressedKeys[j])
          break;
      }
    }
    
    return dp[0];
  }
};