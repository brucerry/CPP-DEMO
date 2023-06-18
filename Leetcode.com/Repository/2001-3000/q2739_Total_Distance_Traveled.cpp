// https://leetcode.com/problems/total-distance-traveled/

// time: O(mainTank)
// space: O(1)

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res = 0;
        while (mainTank) {
            int use = min(5, mainTank);
            mainTank -= use;
            if (use == 5 and additionalTank) {
                mainTank++;
                additionalTank--;
            }
            res += use * 10;
        }
        return res;
    }
};