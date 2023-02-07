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
        int l, r;
        for (l = 0, r = 0; r < fruits.size(); r++) {
            umap[fruits[r]]++;
            if (umap.size() > 2) {
                if (--umap[fruits[l]] == 0)
                    umap.erase(fruits[l]);
                l++;
            }
        }
        return r - l;
    }
};