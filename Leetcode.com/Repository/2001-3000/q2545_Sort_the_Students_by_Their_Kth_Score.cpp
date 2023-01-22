// https://leetcode.com/problems/sort-the-students-by-their-kth-score/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(r * log(r))
// space: O(log(r)) for sorting

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(), score.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[k] > b[k];
        });
        return score;
    }
};