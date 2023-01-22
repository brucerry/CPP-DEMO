// https://leetcode.com/problems/maximum-subsequence-score/

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// time: O(n * log(n) + n * log(k))
// space: O(n + k)

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums1.size(); i++) {
            pairs.emplace_back(nums2[i], nums1[i]);
        }
        sort(pairs.rbegin(), pairs.rend());
        priority_queue<int, vector<int>, greater<>> minHeap;
        long res = 0, sum = 0;
        for (const auto& [ n2, n1 ] : pairs) {
            minHeap.emplace(n1);
            sum += n1;
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == k) {
                res = max(res, sum * n2);
            }
        }
        return res;
    }
};