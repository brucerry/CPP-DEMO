// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

#include <vector>
using namespace std;

// time: O(n * log(1e7))
// space: O(1)

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0, r = 1e7;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (canGet(candies, k, m))
                l = m;
            else
                r = m - 1;
        }
        return l;
    }

private:
    bool canGet(vector<int>& candies, long long k, int test_max) {
        long long total = 0;
        for (int candy : candies) {
            total += candy / test_max;
        }
        return total >= k;
    }
};