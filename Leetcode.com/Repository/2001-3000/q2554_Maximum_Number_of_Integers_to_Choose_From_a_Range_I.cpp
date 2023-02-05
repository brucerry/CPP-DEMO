// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/

#include <vector>
#include <unordered_set>
using namespace std;

// b = size of banned
// time: O(b + n)
// space: O(b)

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> uset (banned.begin(), banned.end());
        long sum = 0, count = 0;
        for (int i = 1; i <= n; i++) {
            if (uset.count(i) == 0 and sum + i <= maxSum) {
                sum += i;
                count++;
            }
        }
        return count;
    }
};