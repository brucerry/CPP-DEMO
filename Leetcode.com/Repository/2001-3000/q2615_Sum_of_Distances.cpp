// https://leetcode.com/problems/sum-of-distances/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res (n);
        unordered_map<int, long long> count, sum;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            res[i] += abs(i * count[num] - sum[num]);
            count[num]++;
            sum[num] += i;
        }
        count = sum = {};
        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            res[i] += abs(i * count[num] - sum[num]);
            count[num]++;
            sum[num] += i;
        }
        return res;
    }
};