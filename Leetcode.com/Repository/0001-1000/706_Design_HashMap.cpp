// https://leetcode.com/problems/design-hashmap/

// time: O(n), amortized O(1)
// space: O(n)

struct Node {
  int key, val;
  Node* next;
  Node(int key, int val, Node* next)
    : key(key), val(val), next(next) {}
};

class MyHashMap {
public:
  MyHashMap() {
    
  }
  
  void put(int key, int value) {
    remove(key);
    int h = hash(key);
    Node* node = new Node(key, value, hashmap[h]);
    hashmap[h] = node;
  }
  
  int get(int key) {
    int h = hash(key);
    for (Node* cur = hashmap[h]; cur; cur = cur->next) {
      if (cur->key == key)
        return cur->val;
    }
    return -1;
  }
  
  void remove(int key) {
    int h = hash(key);
    for (Node* cur = hashmap[h]; cur; cur = cur->next) {
      if (cur->key == key) {
        hashmap[h] = cur->next;
        delete cur;
        return;
      }
      else if (cur->next and cur->next->key == key) {
        Node* tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
        return;
      }
    }
  }
  
private:
  #define SIZE 19997
  #define MULT 12582917
  
  Node* hashmap[SIZE] {};
  
  int hash(long key) {
    return key * MULT % SIZE;
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */