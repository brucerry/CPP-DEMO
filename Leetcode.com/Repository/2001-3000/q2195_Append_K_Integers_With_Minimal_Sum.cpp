// https://leetcode.com/problems/append-k-integers-with-minimal-sum/

#include <vector>
#include <set>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> numset (nums.begin(), nums.end());

        int prev = 0;
        long long res = 0;
        for (int num : numset) {
            int left = prev + 1, right = min(num - 1, prev + k);
            res += sum(left, right);
            k -= right - left + 1;
            if (k == 0)
                break;
            prev = num;
        }
        if (k) {
            res += sum(*numset.rbegin() + 1, *numset.rbegin() + k);
        }
        return res;
    }

private:
    long long sum(int left, int right) {
        return (left + right) * 1L * (right - left + 1) / 2;
    }
};