// https://leetcode.com/problems/minimize-deviation-in-array/

#include <vector>
#include <set>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> numset;
        for (const int& num : nums) {
            numset.insert(num % 2 ? num * 2 : num);
        }
        int res = *numset.rbegin() - *numset.begin();
        while (*numset.rbegin() % 2 == 0) {
            numset.insert(*numset.rbegin() / 2);
            numset.erase(prev(numset.end()));
            res = min(res, *numset.rbegin() - *numset.begin());
        }
        return res;
    }
};