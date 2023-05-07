// https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/

#include <vector>
#include <cmath>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int res = 0;
        for (int i = n / 2 - 1; i >= 0; i--) {
            int leftcost = cost[i*2+1];
            int rightcost = cost[i*2+2];
            res += abs(leftcost - rightcost);
            cost[i] += max(leftcost, rightcost);
        }
        return res;
    }
};