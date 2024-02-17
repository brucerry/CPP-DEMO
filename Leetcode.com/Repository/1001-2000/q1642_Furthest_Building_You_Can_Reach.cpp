// https://leetcode.com/problems/furthest-building-you-can-reach/

#include <vector>
#include <queue>
using namespace std;

// n = size of heights
// k = ladders
// time: O(n * log(k))
// space: O(k)

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<>> minheap;
        for (int i = 0; i < n - 1; i++) {
            if (heights[i] < heights[i+1]) {
                minheap.emplace(heights[i+1] - heights[i]);
                if (minheap.size() > ladders) {
                    bricks -= minheap.top();
                    minheap.pop();
                    if (bricks < 0)
                        return i;
                }
            }
        }
        return n - 1;
    }
};