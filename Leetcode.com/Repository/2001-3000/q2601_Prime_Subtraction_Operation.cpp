// https://leetcode.com/problems/prime-subtraction-operation/

#include <vector>
#include <cstring>
using namespace std;

// time: O(n * max(nums))
// space: O(max(nums))

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int isprime[1001];
        memset(isprime, -1, sizeof(isprime));
        buildPrimes(isprime);
        int prev = -1;
        for (int num : nums) {
            int smaller_prime = 1000;
            for (int test = num; test >= 2; test--) {
                if (isprime[test] and test < num and num - test >= prev + 1) {
                    smaller_prime = test;
                    break;
                }
            }
            if (smaller_prime == 1000 and num > prev) {
                prev = num;
                continue;
            }
            num -= smaller_prime;
            if (num < prev)
                return false;
            prev = num;
        }
        return true;
    }

private:
    void buildPrimes(int* isprime) {
        for (int num = 2; num <= 1000; num++) {
            if (isprime[num] == -1) {
                isprime[num] = 1;
                for (int next = num * 2; next <= 1000; next += num) {
                    isprime[next] = 0;
                }
            }
        }
    }
};