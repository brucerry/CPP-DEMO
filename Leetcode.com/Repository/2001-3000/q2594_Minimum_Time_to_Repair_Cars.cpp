// https://leetcode.com/problems/minimum-time-to-repair-cars/

#include <vector>
#include <cmath>
using namespace std;

// time: O(n * log(1e14))
// space: O(1)

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long l = 1, r = 1e14;
        while (l < r) {
            long m = (l + r) / 2;
            if (canRepair(ranks, cars, m))
                r = m;
            else
                l = m + 1;
        }
        return r;
    }

private:
    bool canRepair(vector<int>& ranks, int cars, long mins) {
        long count = 0;
        for (int rank : ranks) {
            long repaired = sqrt(1.0 * mins / rank);
            count += repaired;
        }
        return count >= cars;
    }
};