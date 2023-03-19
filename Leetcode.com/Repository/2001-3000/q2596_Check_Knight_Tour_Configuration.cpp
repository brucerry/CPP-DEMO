// https://leetcode.com/problems/check-knight-tour-configuration/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0])
            return false;
        
        int moves[][2] = {
            { 1, 2 },
            { 1, -2 },
            { 2, 1 },
            { 2, -1 },
            { -1, 2 },
            { -1, -2 },
            { -2, 1 },
            { -2, -1 }
        };
        
        int n = grid.size(), r = 0, c = 0, step = 0;
        
        while (step < n * n - 1) {
            bool found = false;
            for (int i = 0; i < 8; i++) {
                int newr = r + moves[i][0];
                int newc = c + moves[i][1];
                if (min(newr, newc) >= 0 and max(newr, newc) < n and grid[newr][newc] == step + 1) {
                    r = newr;
                    c = newc;
                    step++;
                    found = true;
                }
            }
            if (!found)
                return false;
        }
        
        return true;
    }
};