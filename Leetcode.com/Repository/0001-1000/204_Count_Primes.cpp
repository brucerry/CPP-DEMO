// https://leetcode.com/problems/count-primes/

// time: O(n)
// space: O(n)

class Solution {
public:
  int countPrimes(int n) {
    bool notPrime[n + 1];
    memset(notPrime, false, sizeof(notPrime));

    for (int i = 2; i < sqrt(n); i++) {
      if (!notPrime[i]) {
        for (int j = 2; i * j < n; j++)
          notPrime[i * j] = 1;
      }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
      count += !notPrime[i];
    }
    return count;
  }
};