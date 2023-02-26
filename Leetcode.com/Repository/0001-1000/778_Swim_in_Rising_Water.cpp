// https://leetcode.com/problems/swim-in-rising-water/

#include <vector>
#include <queue>
using namespace std;

// time: O(n^2 * log(n))
// space: O(n^2)

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int moves[] = { 0, 1, 0, -1, 0 }; // 4-dir

        priority_queue<vector<int>, vector<vector<int>>, greater<>> minheap; // depth, r, c
        minheap.push({ grid[0][0], 0, 0 });
        grid[0][0] = -1;

        while (minheap.size()) {
            int depth = minheap.top()[0], r = minheap.top()[1], c = minheap.top()[2];
            minheap.pop();
            if (r == n - 1 and c == n - 1)
                return depth;
            for (int i = 0; i < 4; i++) {
                int newr = r + moves[i];
                int newc = c + moves[i+1];
                if (min(newr, newc) >= 0 and newr < n and newc < n and grid[newr][newc] != -1) {
                    minheap.push({ max(grid[newr][newc], depth), newr, newc });
                    grid[newr][newc] = -1;
                }
            }
        }

        return -1;
    }
};