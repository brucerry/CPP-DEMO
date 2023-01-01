// https://leetcode.com/problems/closest-prime-numbers-in-range/

#include <vector>
using namespace std;

// time: O(right)
// space: O(right)

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        bool marked[1000001] {};
        vector<int> primes;
        sieve(marked, primes);
        
        int gap = INT_MAX, n1 = -1, n2 = -1;
        int i = lower_bound(primes.begin(), primes.end(), left) - primes.begin();
        for (; i + 1 < primes.size() and primes[i+1] <= right; i++) {
            int l = primes[i];
            int r = primes[i+1];
            if (r - l < gap) {
                gap = r - l;
                n1 = l;
                n2 = r;
            }
        }
        return { n1, n2 };
    }
    
private:
    void sieve(bool* marked, vector<int>& primes) {
        for (int num = 2; num <= 1000000; num++) {
            if (!marked[num]) {
                primes.emplace_back(num);
                for (int p = num; p <= 1000000; p += num) {
                    marked[p] = true;
                }
            }
        }
    }
};