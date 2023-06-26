// https://leetcode.com/problems/total-cost-to-hire-k-workers/

#include <vector>
#include <queue>
#include <array>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> minheap; // cost, i, left/right
        int n = costs.size(), l = 0, r = n - 1;
        while (l <= r and candidates) {
            if (l < r) {
                minheap.push({ costs[r], r, 1 });
            }
            minheap.push({ costs[l], l, 0 });
            l++;
            r--;
            candidates--;
        }

        long res = 0;
        while (k) {
            auto [ cost, i, side ] = minheap.top();
            minheap.pop();
            res += cost;
            k--;
            if (l <= r) {
                if (side == 0)
                    minheap.push({ costs[l], l, side }), l++;
                else
                    minheap.push({ costs[r], r, side }), r--;
            }
        }

        return res;
    }
};