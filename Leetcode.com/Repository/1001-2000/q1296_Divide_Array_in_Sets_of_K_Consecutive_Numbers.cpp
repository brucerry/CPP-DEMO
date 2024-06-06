// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k)
            return false;
        unordered_map<int, int> cnt;
        priority_queue<int, vector<int>, greater<>> minheap;
        for (int num : nums) {
            if (++cnt[num] == 1)
                minheap.emplace(num);
        }
        while (minheap.size()) {
            for (int num = minheap.top(), last = num + k; num < last; ++num) {
                if (!cnt.contains(num))
                    return false;
                if (--cnt[num] == 0) {
                    if (minheap.top() != num)
                        return false;
                    minheap.pop();
                }
            }
        }
        return true;
    }
};