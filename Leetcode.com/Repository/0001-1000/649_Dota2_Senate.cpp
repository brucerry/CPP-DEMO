// https://leetcode.com/problems/dota2-senate/

#include <string>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> que_r, que_d;
        int n = senate.size();
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                que_r.emplace(i);
            else
                que_d.emplace(i);
        }
        while (que_r.size() and que_d.size()) {
            int r = que_r.front();
            que_r.pop();
            int d = que_d.front();
            que_d.pop();
            if (r < d)
                que_r.emplace(r + n);
            else
                que_d.emplace(d + n);
        }
        return que_r.size() > que_d.size() ? "Radiant" : "Dire";
    }
};