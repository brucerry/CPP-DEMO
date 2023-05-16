// https://leetcode.com/problems/range-frequency-queries/

#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// time: O(n) for constructor, O(log(n)) for query()
// space: O(n)

class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> indices;

    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            indices[arr[i]].emplace_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto l = lower_bound(indices[value].begin(), indices[value].end(), left);
        auto r = upper_bound(indices[value].begin(), indices[value].end(), right);
        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */