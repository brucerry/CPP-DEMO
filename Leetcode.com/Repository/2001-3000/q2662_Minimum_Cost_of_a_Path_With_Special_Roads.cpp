// https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/

#include <vector>
#include <unordered_map>
#include <queue>
#include <array>
using namespace std;

// time: O(n^2 * log(n))
// space: O(n)

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        unordered_map<long, vector<array<long, 2>>> umap; // coord1, { coord2, cost }
        umap[coord(target[0], target[1])] = { { 0, 0 } };
        for (auto& sr : specialRoads) {
            long x1 = sr[0], y1 = sr[1], x2 = sr[2], y2 = sr[3], cost = sr[4];
            umap[coord(x1, y1)].push_back({ coord(x2, y2), cost });
        }

        unordered_map<long, long> mincost; // coord, cost
        mincost[coord(start[0], start[1])] = 0;

        priority_queue<array<long, 2>, vector<array<long, 2>>, greater<>> minheap; // cost, coord
        minheap.push({ 0, coord(start[0], start[1]) });

        while (minheap.size()) {
            auto [ cost, coor ] = minheap.top();
            minheap.pop();

            long x = extract_x(coor), y = extract_y(coor);
            if (x == target[0] and y == target[1])
                return cost;

            for (auto& [ nextcoor, nextcost ] : umap[coor]) {
                if (mincost.count(nextcoor) == 0 or cost + nextcost < mincost[nextcoor]) {
                    mincost[nextcoor] = cost + nextcost;
                    minheap.push({ cost + nextcost, nextcoor });
                }
            }

            for (auto& [ nextcoor, _ ] : umap) {
                long newcost = cost + abs(x - extract_x(nextcoor)) + abs(y - extract_y(nextcoor));
                if (mincost.count(nextcoor) == 0 or newcost < mincost[nextcoor]) {
                    mincost[nextcoor] = newcost;
                    minheap.push({ newcost, nextcoor });
                }
            }
        }

        return -1;
    }

private:
    long coord(long x, long y) {
        return x * 100001 + y;
    }

    long extract_x(long coor) {
        return coor / 100001;
    }

    long extract_y(long coor) {
        return coor % 100001;
    }
};