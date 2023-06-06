// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int num : arr) {
            if (num < min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2) {
                min2 = num;
            }
        }

        int diff = min2 - min1;
        unordered_set<int> numset (arr.begin(), arr.end());

        if (numset.size() < arr.size())
            return diff == 0 and numset.size() == 1;

        int match = 1;
        while (numset.count(min1 + diff)) {
            match++;
            min1 += diff;
        }

        return match == arr.size();
    }
};