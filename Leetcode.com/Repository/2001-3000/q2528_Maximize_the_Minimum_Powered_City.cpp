// https://leetcode.com/problems/maximize-the-minimum-powered-city/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n * log(sum(stations) + k))
// space: O(n)

class Solution {
public:
    long long maxPower(vector<int>& stations, int range, int k) {
        long l = 0;
        long r = accumulate(stations.begin(), stations.end(), 0L) + k;
        while (l < r) {
            long m = l + (r - l + 1) / 2;
            if (canSolve(stations, range, k, m))
                l = m;
            else
                r = m - 1;
        }
        return l;
    }

private:
    bool canSolve(vector<int>& stations, int range, int k, long minPower) {
        int n = stations.size();
        vector<int> add (n);
        long curPower = accumulate(stations.begin(), stations.begin() + range, 0L);
        for (int i = 0; i < n; i++) {
            if (i + range < n)
                curPower += stations[i+range] + add[i+range];
            
            if (curPower < minPower) {
                long needed = minPower - curPower;
                if (needed > k)
                    return false;
                k -= needed;
                add[min(n - 1, i + range)] += needed;
                curPower = minPower;
            }

            if (i - range >= 0)
                curPower -= stations[i-range] + add[i-range];
        }
        return true;
    }
};