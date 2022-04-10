// https://leetcode.com/problems/copy-list-with-random-pointer/

#include <unordered_map>
using namespace std;

class Node {
public:
  int val;
  Node* next;
  Node* random;
  
  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

// n = len of list
// time: O(n)
// space: O(n)

class Solution {
public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> map { // originalNode, copyNode
      { nullptr, nullptr }
    };
    
    Node* cur = head;
    
    while (cur) {
      map[cur] = new Node(cur->val);
      cur = cur->next;
    }
    
    cur = head;
    
    while (cur) {
      Node* copy = map[cur];
      copy->next = map[cur->next];
      copy->random = map[cur->random];
      cur = cur->next;
    }
    
    return map[head];
  }
};