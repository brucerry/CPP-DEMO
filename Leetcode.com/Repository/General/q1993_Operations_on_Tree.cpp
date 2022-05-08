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
    m_Parent = parent;
    m_Child.resize(n);
    for (int i = 1; i < n; i++)
      m_Child[parent[i]].emplace_back(i);
    for (int i = 0; i < n; i++)
      m_Locked.emplace_back(0);
  }
  
  bool lock(int num, int user) {
    if (m_Locked[num])
      return false;
    return m_Locked[num] = user;
  }
  
  bool unlock(int num, int user) {
    if (!m_Locked[num] or m_Locked[num] != user)
      return false;
    m_Locked[num] = 0;
    return true;
  }
  
  bool upgrade(int num, int user) {
    // check if self and ancestors are unlocked
    int cur = num;
    while (cur != -1) {
      if (m_Locked[cur])
        return false;
      cur = m_Parent[cur];
    }
    
    bool success = false;
    
    // check if at least 1 descendant is locked
    // and to unlock all descendants
    queue<int> queue;
    for (const int& child : m_Child[num])
      queue.emplace(child);
    while (queue.size()) {
      int size = queue.size();
      while (size--) {
        int node = queue.front();
        queue.pop();
        if (m_Locked[node]) {
          m_Locked[node] = 0;
          success = true;
        }
        for (const int& child : m_Child[node])
          queue.emplace(child);
      }
    }
    
    // if true, lock the node by user
    if (success)
      m_Locked[num] = user;
    
    return success;
  }
  
private:
  vector<int> m_Parent;
  vector<vector<int>> m_Child;
  vector<int> m_Locked;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */