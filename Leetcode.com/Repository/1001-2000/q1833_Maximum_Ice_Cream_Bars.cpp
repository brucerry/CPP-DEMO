// https://leetcode.com/problems/maximum-ice-cream-bars/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int counts[100001] {};
        for (const int& cost : costs) {
            counts[cost]++;
        }
        int res = 0;
        for (int cost = 1; cost <= 100000; cost++) {
            int buy = min(coins / cost, counts[cost]);
            res += buy;
            coins -= buy * cost;
        }
        return res;
    }
};