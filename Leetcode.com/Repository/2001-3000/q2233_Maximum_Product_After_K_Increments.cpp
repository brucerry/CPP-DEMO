// https://leetcode.com/problems/maximum-product-after-k-increments/

#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(n) + k * log(n))
// space: O(n)

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> minheap (nums.begin(), nums.end());
        while (k--) {
            int num = minheap.top();
            minheap.pop();
            minheap.emplace(num + 1);
        }
        long long res = 1, mod = 1e9 + 7;
        while (minheap.size()) {
            res = res * minheap.top() % mod;
            minheap.pop();
        }
        return res;
    }
};