// https://leetcode.com/problems/k-items-with-the-maximum-sum/

// time: O(1)
// space: O(1)

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        return min(k, numOnes) - max(0, k - numOnes - numZeros);
    }
};