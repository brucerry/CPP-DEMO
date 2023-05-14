// https://leetcode.com/problems/find-the-losers-of-the-circular-game/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> receive (n);
        int id = 0, round = 1;
        while (true) {
            if (receive[id])
                break;
            receive[id] = 1;
            id = (id + k * round) % n;
            round++;
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (receive[i] == 0) {
                res.emplace_back(i + 1);
            }
        }
        return res;
    }
};