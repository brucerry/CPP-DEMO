// https://leetcode.com/problems/find-the-winner-of-an-array-game/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size(), win = 0, next = 1, count = 0;
        while (win != next and count < k) {
            if (arr[win] > arr[next]) {
                next = (next + 1) % n;
                count++;
            }
            else {
                win = next;
                next = (next + 1) % n;
                count = 1;
            }
        }
        return arr[win];
    }
};