// https://leetcode.com/problems/ipo/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// time: O(n * log(n) + k * log(n))
// space: O(n)

class Solution {
public:
    int findMaximizedCapital(int k, int totalCapital, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<vector<int>> pairs; // { cap, profit }
        for (int i = 0; i < n; i++) {
            pairs.push_back({ capital[i], profits[i] });
        }
        sort(pairs.begin(), pairs.end());

        int i = 0;
        priority_queue<int> maxheap; // profit
        while (k--) {
            while (i < n and totalCapital >= pairs[i][0]) {
                maxheap.emplace(pairs[i][1]);
                i++;
            }
            if (maxheap.size()) {
                totalCapital += maxheap.top();
                maxheap.pop();
            }
        }

        return totalCapital;
    }
};