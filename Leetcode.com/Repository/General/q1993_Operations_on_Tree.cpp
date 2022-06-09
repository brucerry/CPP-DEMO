// https://leetcode.com/problems/operations-on-tree/

#include <vector>
#include <queue>
using namespace std;

// time: O(1) for lock() and unlock(), O(n) for constructor and upgrade()
// space: O(n)

class LockingTree {
public:
  LockingTree(vector<int>& parent) {
    int n = parent.size();
    parents = parent;
    locked.resize(n);
    children.resize(n);
    for (int node = 1; node < n; node++) {
      children[parent[node]].emplace_back(node);
    }
  }
  
  bool lock(int num, int user) {
    if (locked[num])
      return false;
    return locked[num] = user;
  }
  
  bool unlock(int num, int user) {
    if (!locked[num] or locked[num] != user)
      return false;
    locked[num] = 0;
    return true;
  }
  
  bool upgrade(int num, int user) {
    // check if self and ancestors are unlocked
    int cur = num;
    while (cur != -1) {
      if (locked[cur])
        return false;
      cur = parents[cur];
    }
    
    bool success = false;
    
    // check if at least 1 descendant is locked
    // and to unlock all descendants
    queue<int> queue;
    for (const int& child : children[num])
      queue.emplace(child);
    while (queue.size()) {
      int node = queue.front();
      queue.pop();
      if (locked[node]) {
        locked[node] = 0;
        success = true;
      }
      for (const int& child : children[node])
        queue.emplace(child);
    }
    
    return success and (locked[num] = user);
  }
  
private:
  vector<int> locked;
  vector<int> parents;
  vector<vector<int>> children;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */