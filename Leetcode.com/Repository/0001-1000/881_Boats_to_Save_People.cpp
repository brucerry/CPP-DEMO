// https://leetcode.com/problems/boats-to-save-people/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0;
        for (int l = 0, r = people.size() - 1; l <= r; r--) {
            if (people[l] + people[r] <= limit) {
                l++;
            }
            res++;
        }
        return res;
    }
};