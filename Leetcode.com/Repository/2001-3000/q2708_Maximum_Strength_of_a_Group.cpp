// https://leetcode.com/problems/maximum-strength-of-a-group/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        
        int z = 0;
        int p = 0;
        int n = 0;
        
        long pos_product = 1, neg_product = 1, max_neg = -10;
        for (long num : nums) {
            if (num < 0)
                neg_product *= num, n++, max_neg = max(max_neg, num);
            else if (num > 0)
                pos_product *= num, p++;
            else
                z++;
        }
        
        if (!n and !p)
            return 0;
        
        if (!p) {
            if (n and z and n == 1)
                return 0;
        }
        
        long product = pos_product * neg_product;
        return n & 1 ? product / max_neg : product;
    }
};