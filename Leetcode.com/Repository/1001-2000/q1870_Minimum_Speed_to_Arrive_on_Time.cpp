// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

#include <vector>
using namespace std;

// time: O(n * log(1e7))
// space: O(1)

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() - 1 >= hour)
            return -1;

        int l = 1, r = 1e7;
        while (l < r) {
            int m = (l + r) / 2;
            if (solve(dist, hour, m))
                r = m;
            else
                l = m + 1;
        }
        return r;
    }

private:
    bool solve(vector<int>& dist, double hour, int test_speed) {
        double need = 0;
        for (int i = 0; i < dist.size() - 1; i++) {
            need += (dist[i] + test_speed - 1) / test_speed;
        }
        return need + (double)dist.back() / test_speed <= hour;
    }
};