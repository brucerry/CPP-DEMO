// https://leetcode.com/problems/lru-cache/

#include <unordered_map>
using namespace std;

// double linked list
// time: O(1) for operations
// space: O(n)

class LRUCache {
public:
  LRUCache(int capacity) : cap(capacity), LRU(new Node()), MRU(new Node()) {
    LRU->right = MRU;
    MRU->left = LRU;
  }
  
  int get(int key) {
    if (cache.count(key) == 0)
      return -1;
    Node* node = cache[key];
    remove(node);
    insert(node);
    return node->val;
  }
  
  void put(int key, int value) {
    if (cache.count(key)) {
      Node* node = cache[key];
      node->val = value;
      remove(node);
      insert(node);
    }
    else {
      Node* node = new Node(key, value);
      cache[key] = node;
      insert(node);
      if (cache.size() > cap) {
        Node* lru = LRU->right;
        remove(lru);
        cache.erase(lru->key);
      }
    }
  }
  
private:
  struct Node {
    int key, val;
    Node* left, *right;
    
    Node() : key(0), val(0), left(nullptr), right(nullptr) {}
    Node(int key, int val) : key(key), val(val), left(nullptr), right(nullptr) {}
    Node(int key, int val, Node* left, Node* right) : key(key), val(val), left(left), right(right) {}
  };
  
  unordered_map<int, Node*> cache; // key, Node*
  Node* LRU, *MRU;
  int cap;
  
private:
  void remove(Node* node) {
    node->left->right = node->right;
    node->right->left = node->left;
    node->left = node->right = nullptr;
  }
  
  void insert(Node* node) {
    node->right = MRU;
    node->left = MRU->left;
    node->left->right = MRU->left = node;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */