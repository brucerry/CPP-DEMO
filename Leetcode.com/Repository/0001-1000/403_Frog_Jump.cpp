// https://leetcode.com/problems/frog-jump/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_map<int, bool>> memo;
        return solve(stones, memo, 0, 0);
    }

private:
    int solve(vector<int>& stones, unordered_map<int, unordered_map<int, bool>>& memo, int cur, int jump) {
        if (cur == stones.size() - 1)
            return true;

        if (memo[cur].count(jump))
            return memo[cur][jump];

        bool& res = memo[cur][jump] = false;
        for (int next = cur + 1; next < stones.size(); next++) {
            int diff = stones[next] - stones[cur];
            if (jump - 1 == diff or jump == diff or jump + 1 == diff)
                res = res or solve(stones, memo, next, diff);
        }
        return res;
    }
};