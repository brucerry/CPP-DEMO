// https://leetcode.com/problems/number-of-beautiful-pairs/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n * log(nums[i]))
// space: O(1)

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int res = 0, count[10] {};
        for (int num : nums) {
            for (int d = 1; d <= 9; d++) {
                if (gcd(d, num % 10) == 1) {
                    res += count[d];
                }
            }
            while (num / 10) {
                num /= 10;
            }
            count[num]++;
        }
        return res;
    }
};