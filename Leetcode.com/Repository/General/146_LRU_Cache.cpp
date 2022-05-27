// https://leetcode.com/problems/lru-cache/

#include <unordered_map>
using namespace std;

// double linked list
// time: O(1) for operations
// space: O(n)

class LRUCache {
public:
  LRUCache(int capacity) : m_Capacity(capacity) {
    m_MRU.left = &m_LRU;
    m_LRU.right = &m_MRU;
  }
  
  int get(int key) {
    if (m_Cache.count(key) == 0)
      return -1;
    
    Node* node = m_Cache[key];
    remove(node);
    insert(node);
    return node->val;
  }
  
  void put(int key, int value) {
    if (m_Cache.count(key)) {
      Node* node = m_Cache[key];
      remove(node);
      insert(node);
      node->val = value;
    }
    else {
      Node* newNode = new Node(key, value);
      m_Cache[key] = newNode;
      insert(newNode);
      if (m_Cache.size() > m_Capacity) {
        Node* lru = m_LRU.right;
        remove(lru);
        m_Cache.erase(lru->key);
      }
    }
  }

private:
  struct Node {
    int key, val;
    Node* left, *right;

    Node() : left(nullptr), right(nullptr) {};
    Node(int key, int val) : key(key), val(val), left(nullptr), right(nullptr) {};
  };
  
  int m_Capacity;
  Node m_MRU; // most recently used, on the right most side
  Node m_LRU; // least recently used, on the left most side
  unordered_map<int, Node*> m_Cache; // key, Node*

private:
  // insert node to MRU
  void insert(Node* node) {
    node->left = m_MRU.left;
    node->right = &m_MRU;
    m_MRU.left = m_MRU.left->right = node;
  }
  
  // remove node from list
  void remove(Node* node) {
    node->left->right = node->right;
    node->right->left = node->left;
    node->left = node->right = nullptr;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */