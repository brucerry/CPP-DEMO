// https://leetcode.com/problems/snapshot-array/

#include <unordered_map>
#include <map>
using namespace std;

// time: set & get - O(log(n)), snap - O(1)
// space: O(n)

class SnapshotArray {
public:
    unordered_map<int, map<int, int>> cache; // index, { id, val }
    int id = 0;

    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        cache[index][id] = val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto it = cache[index].upper_bound(snap_id);
        return it == cache[index].begin() ? 0 : prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */