// https://leetcode.com/problems/lru-cache/

#include <unordered_map>
using namespace std;

// double linked list
// time: O(1) for operations
// space: O(n)

struct Node {
  int key, val;
  Node* prev, *next;

  Node(int key, int value)
    : key(key), val(value), prev(nullptr), next(nullptr) {};
};

class LRUCache {
private:
  int cap;
  unordered_map<int, Node*> cache; // key, node
  Node* leastRecentlyUsed; // dummy node on the left
  Node* mostRecentlyUsed; // dummy node on the right

  // remove node from list
  void remove(Node* node) {
    Node* prev = node->prev, *next = node->next;
    prev->next = next;
    next->prev = prev;
    delete &node;
  }

  // insert node at mostRecentlyUsed
  void insert(Node* node) {
    Node* prev = mostRecentlyUsed->prev;
    prev->next = mostRecentlyUsed->prev = node;
    node->prev = prev;
    node->next = mostRecentlyUsed;
  }
  
public:
  LRUCache(int capacity) : cap(capacity), cache({}), leastRecentlyUsed(new Node(0, 0)), mostRecentlyUsed(new Node(0, 0)) {
    leastRecentlyUsed->next = mostRecentlyUsed;
    mostRecentlyUsed->prev = leastRecentlyUsed;
  }

  ~LRUCache() {
    for (auto [ key, node ] : cache) {
      delete cache[key];
    }
  }
    
  int get(int key) {
    if (cache.count(key)) {
      remove(cache[key]);
      insert(cache[key]);
      return cache[key]->val;
    }
    return -1;
  }
    
  void put(int key, int value) {
    if (cache.count(key)) {
      remove(cache[key]);
    }
    cache[key] = new Node(key, value);
    insert(cache[key]);

    if (cache.size() > cap) {
      Node* lru = leastRecentlyUsed->next;
      remove(lru);
      cache.erase(lru->key);
    }
  }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */