// https://leetcode.com/problems/design-skiplist/

#include <vector>
#include <random>
using namespace std;

struct Node {
  int val;
  Node* next, *down;
  Node(int val, Node* next, Node* down) : val(val), next(next), down(down) {}
};

// time: O(1) for constructor, O(log(n)) for search(), add(), erase()
// space: O(n)

class Skiplist {
public:
  Skiplist() {
    dummy = new Node(INT_MIN, nullptr, nullptr);
    
    random_device rd;
    gen = mt19937(rd());
    distrib = uniform_int_distribution<int>(0, 1);
  }
  
  bool search(int target) {
    Node* cur = dummy;
    while (cur) {
      while (cur->next and cur->next->val < target)
        cur = cur->next;
      if (cur->next and cur->next->val == target)
        return true;
      cur = cur->down;
    }
    return false;
  }
  
  void add(int num) {
    vector<Node*> stack;
    Node* cur = dummy;
    while (cur) {
      while (cur->next and cur->next->val < num)
        cur = cur->next;
      stack.emplace_back(cur);
      cur = cur->down;
    }
    
    bool isCoinHead = true;
    Node* down = nullptr;
    while (isCoinHead and stack.size()) {
      cur = stack.back();
      stack.pop_back();
      cur->next = new Node(num, cur->next, down);
      down = cur->next;
      isCoinHead = filpCoin();
    }
    
    if (isCoinHead)
      dummy = new Node(INT_MIN, nullptr, dummy);
  }
  
  bool erase(int num) {
    bool erased = false;
    Node* cur = dummy;
    while (cur) {
      while (cur->next and cur->next->val < num)
        cur = cur->next;
      if (cur->next and cur->next->val == num) {
        Node* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        erased = true;
      }
      cur = cur->down;
    }
    return erased;
  }
  
private:
  Node* dummy;
  
  mt19937 gen;
  uniform_int_distribution<int> distrib;
  
  int filpCoin() {
    return distrib(gen);
  }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */