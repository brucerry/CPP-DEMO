// https://leetcode.com/problems/bus-routes/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> busID;
        for (int busid = 0; busid < routes.size(); busid++) {
            for (int stop : routes[busid]) {
                busID[stop].emplace_back(busid);
            }
        }

        queue<int> que;
        que.emplace(source);

        unordered_set<int> seen_stop { source }, seen_bus;

        int res = 0;
        while (que.size()) {
            for (int size = que.size(); size; size--) {
                int cur_stop = que.front();
                que.pop();
                if (cur_stop == target)
                    return res;
                for (int busid : busID[cur_stop]) {
                    if (seen_bus.count(busid) == 0) {
                        seen_bus.emplace(busid);
                        for (int next_stop : routes[busid]) {
                            if (seen_stop.count(next_stop) == 0) {
                                seen_stop.emplace(next_stop);
                                que.emplace(next_stop);
                            }
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};