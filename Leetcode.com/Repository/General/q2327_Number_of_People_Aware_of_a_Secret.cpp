// https://leetcode.com/problems/number-of-people-aware-of-a-secret/

#include <vector>
using namespace std;

// time: O(n)
// space: O(forget)
class SpaceOptimizedDP {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<long> dp (forget);
    dp[0] = 1;
    
    int share = 0;
    for (int curDay = 1; curDay < n; curDay++) {
      dp[curDay % forget] = share = (share + dp[(curDay - delay + forget) % forget] - dp[curDay % forget] + 1000000007) % 1000000007;
    }
    
    int people = 0;
    for (const long& ppl : dp) {
      people = (people + ppl) % 1000000007;
    }
    
    return people;
  }
};

// time: O(n)
// space: O(n)
class DP {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<long> dp (n + 1);
    dp[1] = 1;
    
    int share = 0;
    for (int curDay = 2; curDay <= n; curDay++) {
      dp[curDay] = share = (share + dp[max(0, curDay - delay)] - dp[max(0, curDay - forget)] + 1000000007) % 1000000007;
    }
    
    int people = 0;
    for (int curDay = n - forget + 1; curDay <= n; curDay++) {
      people = (people + dp[curDay]) % 1000000007;
    }
    
    return people;
  }
};