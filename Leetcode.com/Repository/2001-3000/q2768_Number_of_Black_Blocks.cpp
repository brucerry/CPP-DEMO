// https://leetcode.com/problems/number-of-black-blocks/

#include <vector>
#include <unordered_set>
using namespace std;

// b = size of blacks
// time: O(b)
// space: O(b)

class Solution {
public:
    vector<long long> countBlackBlocks(int rows, int cols, vector<vector<int>>& blacks) {
        unordered_set<long> uset;
        for (auto& black : blacks) {
            int r = black[0];
            int c = black[1];
            uset.emplace(r * 100000L + c);
        }

        int count[5] {};
        for (auto& black : blacks) {
            int r = black[0];
            int c = black[1];
            for (int x = max(0, r - 1); x <= min(rows - 2, r); x++) {
                for (int y = max(0, c - 1); y <= min(cols - 2, c); y++) {
                    int sum = exist(uset, x, y) + exist(uset, x+1, y) + exist(uset, x, y+1) + exist(uset, x+1, y+1);
                    count[sum]++;
                }
            }
        }

        int one = count[1];
        int two = count[2] / 2;
        int three = count[3] / 3;
        int four = count[4] / 4;
        return { 1L * (rows - 1) * (cols - 1) - one - two - three - four, one, two, three, four };
    }

private:
    bool exist(unordered_set<long>& uset, int r, int c) {
        return uset.count(r * 100000L + c);
    }
};