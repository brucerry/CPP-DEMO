// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <vector>
using namespace std;

// max = max of bloomDay
// time: O(n * log(max))
// space: O(1)

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1L * m * k > bloomDay.size())
            return -1;
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (ok(bloomDay, m, k, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }

    int ok(vector<int>& bloomDay, int m, int k, int mid) {
        int bouquets = 0, cnt = 0;
        for (int b : bloomDay) {
            if (mid >= b) {
                if (++cnt == k) {
                    cnt = 0;
                    ++bouquets;
                }
            }
            else
                cnt = 0;
        }
        return bouquets >= m;
    }
};