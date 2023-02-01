// https://leetcode.com/problems/best-team-with-no-conflicts/

#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> indices (n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return scores[i] == scores[j] ? ages[i] < ages[j] : scores[i] < scores[j];
        });

        map<int, int> map { // age, score
            { 0, 0 }
        };
        for (const int& i : indices) {
            int score = scores[i];
            int age = ages[i];
            auto it = map.upper_bound(age);
            score += prev(it)->second;
            map[age] = score;
            while (it != map.end() and it->second <= score) {
                it = next(it);
                map.erase(prev(it));
            }
        }
        return map.rbegin()->second;
    }
};