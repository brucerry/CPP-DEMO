// https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> uset;
        for (int& num : nums) {
            for (int f = 2; f <= sqrt(num); f++) {
                while (num % f == 0) {
                    uset.emplace(f);
                    num /= f;
                }
            }
            if (num > 1)
                uset.emplace(num);
        }
        return uset.size();
    }
};