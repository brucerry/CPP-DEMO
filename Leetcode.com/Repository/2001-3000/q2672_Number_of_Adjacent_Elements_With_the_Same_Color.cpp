// https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/

#include <vector>
#include <unordered_map>
using namespace std;

// q = size of queries
// time: O(q)
// space: O(n)

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        unordered_map<int, int> index_color;
        int same = 0;
        vector<int> res;
        for (auto& que : queries) {
            int index = que[0];
            int new_color = que[1];
            
            int org_color = index_color[index];
            index_color[index] = new_color;
            
            same += index_color[index+1] and index_color[index+1] == new_color;
            same += index_color[index-1] and index_color[index-1] == new_color;

            same -= index_color[index+1] and index_color[index+1] == org_color;
            same -= index_color[index-1] and index_color[index-1] == org_color;
            
            res.emplace_back(same);
        }
        
        return res;
    }
};