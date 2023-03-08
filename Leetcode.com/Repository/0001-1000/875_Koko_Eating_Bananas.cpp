// https://leetcode.com/problems/koko-eating-bananas/

#include <vector>
using namespace std;

// time: O(n * log(1e9))
// space: O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9;
        while (l < r) {
            int m = (l + r) / 2;
            if (canEat(piles, h, m))
                r = m;
            else
                l = m + 1;
        }
        return r;
    }

private:
    bool canEat(vector<int>& piles, int hour, int speed) {
        int needHour = 0;
        for (const int& pile : piles) {
            needHour += (pile + speed - 1) / speed; // ceil((double)pile / speed)
        }
        return needHour <= hour;
    }
};