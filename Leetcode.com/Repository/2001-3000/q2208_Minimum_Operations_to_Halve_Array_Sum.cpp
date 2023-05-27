// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> maxheap;
        double half = 0;
        for (double num : nums) {
            maxheap.emplace(num);
            half += num / 2;
        }

        int res = 0;
        while (half > 0) {
            double num = maxheap.top();
            maxheap.pop();
            half -= num / 2;
            maxheap.emplace(num / 2);
            res++;
        }

        return res;
    }
};