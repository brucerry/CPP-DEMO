// https://leetcode.com/problems/rearranging-fruits/

#include <vector>
#include <map>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        map<int, long> map; // fruit, count
        for (const int& b : b1) {
            map[b]++;
        }
        for (const int& b : b2) {
            map[b]--;
        }
        long swaps = 0, res = 0;
        for (const auto& [ fruit, count ] : map) {
            if (count % 2)
                return -1;
            swaps += max(0L, count / 2);
        }
        for (const auto& [ fruit, count ] : map) {
            long take = min(swaps, abs(count) / 2);
            swaps -= take;
            res += take * min(fruit, map.begin()->first * 2);
        }
        return res;
    }
};