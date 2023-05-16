// https://leetcode.com/problems/time-needed-to-buy-tickets/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        for (int i = 0; i < tickets.size(); i++) {
            res += min(tickets[i], tickets[k] - (i > k));
        }
        return res;
    }
};