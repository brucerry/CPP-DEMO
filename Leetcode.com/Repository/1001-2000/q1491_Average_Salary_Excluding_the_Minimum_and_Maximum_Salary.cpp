// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    double average(vector<int>& salary) {
        int mins = INT_MAX, maxs = 0;
        double sum = 0;
        for (int& s : salary) {
            sum += s;
            mins = min(mins, s);
            maxs = max(maxs, s);
        }
        return (sum - mins - maxs) / (salary.size() - 2);
    }
};