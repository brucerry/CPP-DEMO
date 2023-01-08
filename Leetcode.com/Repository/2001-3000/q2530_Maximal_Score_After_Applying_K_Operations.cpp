// https://leetcode.com/problems/maximal-score-after-applying-k-operations/

#include <vector>
#include <queue>
using namespace std;

// time: O(n + k * log(n))
// space: O(n)

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap (nums.begin(), nums.end());
        long res = 0;
        while (k--) {
            int top = maxHeap.top();
            maxHeap.pop();
            maxHeap.emplace((top + 3 - 1) / 3);
            res += top;
        }
        return res;
    }
};