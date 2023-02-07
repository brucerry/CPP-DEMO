// https://leetcode.com/problems/fruit-into-baskets/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> umap; // fruit, count
        int res = 0;
        for (int l = 0, r = 0; r < fruits.size(); r++) {
            umap[fruits[r]]++;
            if (umap.size() > 2) {
                if (--umap[fruits[l]] == 0)
                    umap.erase(fruits[l]);
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};