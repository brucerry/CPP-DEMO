// https://leetcode.com/problems/snapshot-array/

#include <unordered_map>
using namespace std;

// time: O(n) for snap(), O(1) for set() & get()
// space: O(n)

class SnapshotArray {
public:
  SnapshotArray(int length) : snapCount(0) {
    
  }
  
  void set(int index, int val) {
    m_IndexRecord[index] = val;
  }
  
  int snap() {
    m_SnapRecord[snapCount] = m_IndexRecord;
    
    snapCount++;
    return snapCount - 1;
  }
  
  int get(int index, int snap_id) {
    return m_SnapRecord[snap_id][index];
  }
  
private:  
  unordered_map<int, unordered_map<int, int>> m_SnapRecord; // snap_id, m_IndexRecord
  unordered_map<int, int> m_IndexRecord; // index, value
  int snapCount;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */