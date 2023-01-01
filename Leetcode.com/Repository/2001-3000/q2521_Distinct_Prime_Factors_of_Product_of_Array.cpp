// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        bool isFactor[1001] {};
        for (int& num : nums) {
            for (int f = 2; f <= 1000; f++) {
                while (num % f == 0) {
                    isFactor[f] = true;
                    num /= f;
                }
            }
        }
        int res = 0;
        for (const bool& isfactor : isFactor) {
            res += isfactor;
        }
        return res;
    }
};