// https://leetcode.com/problems/shortest-bridge/

#include <vector>
#include <queue>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c]) {
                    dfs(grid, n, r, c);
                    return bfs(grid, n);
                }
            }
        }
        return -1;
    }

private:
    void dfs(vector<vector<int>>& grid, int n, int r, int c) {
        if (min(r, c) < 0 or max(r, c) >= n or grid[r][c] <= 0)
            return;
        grid[r][c] = -1;
        dfs(grid, n, r+1, c);
        dfs(grid, n, r-1, c);
        dfs(grid, n, r, c+1);
        dfs(grid, n, r, c-1);
    }

    int bfs(vector<vector<int>>& grid, int n) {
        queue<pair<int, int>> que;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == -1)
                    que.emplace(r, c);
            }
        }

        int moves[] = { 0, 1, 0, -1, 0 }; // 4-dir

        int res = 0;
        while (que.size()) {
            for (int size = que.size(); size; size--) {
                auto [ r, c ] = que.front();
                que.pop();
                for (int i = 0; i < 4; i++) {
                    int newr = r + moves[i];
                    int newc = c + moves[i+1];
                    if (min(newr, newc) >= 0 and max(newr, newc) < n and grid[newr][newc] != -1) {
                        if (grid[newr][newc] == 1)
                            return res;
                        grid[newr][newc] = -1;
                        que.emplace(newr, newc);
                    }
                }
            }
            res++;
        }

        return -1;
    }
};