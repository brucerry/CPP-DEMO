// https://leetcode.com/problems/calculate-delayed-arrival-time/

// time: O(1)
// space: O(1)

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};