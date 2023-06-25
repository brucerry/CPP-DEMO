// https://leetcode.com/problems/count-all-possible-routes/

#include <vector>
using namespace std;

// time: O(fuel * n^2)
// space: O(fuel * n)

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> memo (n, vector<int>(fuel + 1, -1));
        return solve(locations, start, finish, fuel, memo);
    }

private:
    int solve(vector<int>& locations, int cur, int dst, int fuel, vector<vector<int>>& memo) {
        if (fuel < 0)
            return 0;
        
        int& res = memo[cur][fuel];
        if (res != -1)
            return res;

        res = cur == dst ? 1 : 0;
        for (int i = 0; i < locations.size(); i++) {
            if (cur != i) {
                res = (res + solve(locations, i, dst, fuel - abs(locations[cur] - locations[i]), memo)) % 1000000007;
            }
        }

        return res;
    }
};