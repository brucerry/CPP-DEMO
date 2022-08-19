// https://leetcode.com/problems/design-hashset/

// time: O(n), amortized O(1)
// space: O(n)

struct Node {
  int key;
  Node* next;
  Node(int key, Node* next)
    : key(key), next(next) {}
};

class MyHashSet {
public:
  MyHashSet() {
    
  }
  
  void add(int key) {
    if (!contains(key)) {
      int h = hash(key);
      Node* node = new Node(key, hashset[h]);
      hashset[h] = node;
    }
  }
  
  void remove(int key) {
    int h = hash(key);
    for (Node* cur = hashset[h]; cur; cur = cur->next) {
      if (cur->key == key) {
        hashset[h] = cur->next;
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
  
  bool contains(int key) {
    int h = hash(key);
    for (Node* cur = hashset[h]; cur; cur = cur->next) {
      if (cur->key == key)
        return true;
    }
    return false;
  }

private:
  #define SIZE 19997
  #define MULT 12582917
  
  Node* hashset[SIZE] {};
  
  int hash(long key) {
    return key * MULT % SIZE;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */