// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> minheap; // end
        int res = 0, n = events.size(), cur_day = 0, i = 0;
        while (i < n or minheap.size()) {
            if (minheap.size() == 0)
                cur_day = events[i][0];
            while (i < n and events[i][0] == cur_day)
                minheap.emplace(events[i++][1]);
            while (minheap.size() and minheap.top() < cur_day)
                minheap.pop();
            if (minheap.size()) {
                res++;
                minheap.pop();
            }
            cur_day++;
        }
        return res;
    }
};