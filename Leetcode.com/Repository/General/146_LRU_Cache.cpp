// https://leetcode.com/problems/lru-cache/

#include <unordered_map>
using namespace std;

// double linked list
// time: O(1) for operations
// space: O(n)

class LRUCache {
private:
  struct Node {
    int key, value;
    Node* left, *right;

    Node() : left(nullptr), right(nullptr) {};
    Node(int key, int value) : key(key), value(value), left(nullptr), right(nullptr) {};
  };
  
  int m_Capacity;
  Node m_MRU; // most recently used, on the right most side
  Node m_LRU; // least recently used, on the left most side
  unordered_map<int, Node*> m_Cache; // key, Node*
  
  // insert node to MRU
  void insert(Node* node) {
    Node* tmp = m_MRU.left;
    tmp->right = m_MRU.left = node;
    node->left = tmp;
    node->right = &m_MRU;
  }
  
  // remove node from list
  void remove(Node* node) {
    Node* lhs = node->left, *rhs = node->right;
    lhs->right = rhs;
    rhs->left = lhs;
    node->left = node->right = nullptr;
  }
  
public:
  LRUCache(int capacity) : m_Capacity(capacity) {
    m_MRU.left = &m_LRU;
    m_LRU.right = &m_MRU;
  }
  
  int get(int key) {
    if (m_Cache.count(key)) {
      remove(m_Cache[key]);
      insert(m_Cache[key]);
      return m_Cache[key]->value;
    }
    return -1;
  }
  
  void put(int key, int value) {
    if (m_Cache.count(key)) {
      remove(m_Cache[key]);
      insert(m_Cache[key]);
      m_Cache[key]->value = value;
    }
    else {
      m_Cache[key] = new Node(key, value);
      insert(m_Cache[key]);
      if (m_Cache.size() > m_Capacity) {
        Node* lru = m_LRU.right;
        remove(lru);
        m_Cache.erase(lru->key);
      }
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */