// https://leetcode.com/problems/find-the-winner-of-an-array-game/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int win = 0;
        int next = 1;
        int cnt = 0;
        while (win != next and cnt < k) {
            if (arr[win] < arr[next]) {
                win = next;
                cnt = 0;
            }
            cnt++;
            next = (next + 1) % n;
        }
        return arr[win];
    }
};