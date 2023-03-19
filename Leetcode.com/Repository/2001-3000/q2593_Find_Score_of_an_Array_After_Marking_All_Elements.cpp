// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/

#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long res = 0;
        int n = nums.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minheap; // value, index
        for (int i = 0; i < n; i++) {
            minheap.emplace(nums[i], i);
        }
        
        while (minheap.size()) {
            auto [ v, i ] = minheap.top();
            minheap.pop();
            
            if (nums[i] == 0)
                continue;
            
            res += v;
            nums[i] = nums[max(0, i - 1)] = nums[min(n - 1, i + 1)] = 0;
        }
        
        return res;
    }
};