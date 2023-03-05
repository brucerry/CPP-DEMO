// https://leetcode.com/problems/split-the-array-to-make-coprime-products/

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// time: O(n * 100)
// space: O(n)

class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        unordered_map<int, unordered_set<int>> primeFactors; // num, prime factors
        unordered_map<int, int> left, right;
        for (int num : nums) {
            getPrimeFactors(primeFactors, num);
            for (int factor : primeFactors[num]) {
                right[factor]++;
            }
        }

        int common = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int factor : primeFactors[nums[i]]) {
                left[factor]++;
                common += left[factor] == 1;
                common -= left[factor] == right[factor];
            }
            if (common == 0) {
                return i;
            }
        }

        return -1;
    }

private:
    void getPrimeFactors(unordered_map<int, unordered_set<int>>& primeFactors, int num) {
        if (primeFactors.count(num) == 0) {
            int copy = num;
            for (int factor = 2; factor <= min(100, copy); factor++) {
                while (num % factor == 0) {
                    primeFactors[copy].insert(factor);
                    num /= factor;
                }
            }
            if (num != 1) {
                primeFactors[copy].insert(num);
            }
        }
    }
};