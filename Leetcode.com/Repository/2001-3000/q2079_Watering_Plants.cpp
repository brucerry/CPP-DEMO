// https://leetcode.com/problems/watering-plants/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int res = 0, cur = capacity;
        for (int i = 0; i < n; i++) {
            if (cur < plants[i]) {
                res += (i + 1) * 2 - 1;
                cur = capacity;
            }
            else {
                res++;
            }
            cur -= plants[i];
        }
        return res;
    }
};