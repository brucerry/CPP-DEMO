// https://leetcode.com/problems/make-array-empty/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        long n = nums.size(), res = n;

        unordered_map<int, int> index; // num, index
        for (int i = 0; i < n; i++) {
            index[nums[i]] = i;
        }

        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++) {
            if (index[nums[i-1]] > index[nums[i]])
                res += n - i;
        }

        return res;
    }
};