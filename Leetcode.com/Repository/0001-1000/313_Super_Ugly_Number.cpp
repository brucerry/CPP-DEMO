// https://leetcode.com/problems/super-ugly-number/

#include <vector>
#include <queue>
#include <array>
using namespace std;

// p = size of primes
// time: O(n * log(p))
// space: O(n + p)
class MinHeapDP {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    int p = primes.size();
    vector<int> dp (n + 1);
    dp[1] = 1;
    
    priority_queue<array<unsigned, 3>, vector<array<unsigned, 3>>, greater<>> minHeap; // value, nextIndex, original prime
    for (const unsigned& prime : primes)
      minHeap.push({ prime, 1, prime });
    
    for (int i = 2; i <= n; i++) {
      dp[i] = minHeap.top()[0];
      while (dp[i] == minHeap.top()[0]) {
        auto [ value, idx, prime ] = minHeap.top();
        minHeap.pop();
        minHeap.push({ prime * dp[idx], idx + 1, prime });
      }
    }
    
    return dp[n];
  }
};

// p = size of primes
// time: O(n * p)
// space: O(n + p)
class DP {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    int p = primes.size();
    vector<unsigned int> dp (n + 1);
    vector<unsigned int> nextIndex (p, 1), values (p, 1);
    
    for (unsigned int ugly = 1, i = 1; i <= n; i++) {
      dp[i] = ugly;
      ugly = INT_MAX;
      for (int j = 0; j < p; j++) {
        if (values[j] == dp[i])
          values[j] = dp[nextIndex[j]++] * primes[j];
        ugly = min(ugly, values[j]);
      }
    }
    
    return dp[n];
  }
};