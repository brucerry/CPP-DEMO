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
class Iterative {
public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> nodeCopy { // originalNode, copyNode
      { nullptr, nullptr }
    };
    
    Node* cur = head;
    while (cur) {
      nodeCopy[cur] = new Node(cur->val);
      cur = cur->next;
    }
    
    cur = head;
    while (cur) {
      Node* copy = nodeCopy[cur];
      copy->next = nodeCopy[cur->next];
      copy->random = nodeCopy[cur->random];

      cur = cur->next;
    }
    
    return nodeCopy[head];
  }
};

// n = len of list
// time: O(n)
// space: O(n)
class Recursive {
public:
  Node* copyRandomList(Node* head) {    
    unordered_map<Node*, Node*> nodeCopy {
      { nullptr, nullptr }
    };
    return solve(head, nodeCopy);
  }
  
private:
  Node* solve(Node* node, unordered_map<Node*, Node*>& nodeCopy) {
    if (nodeCopy.count(node))
      return nodeCopy[node];
    
    Node* copy = new Node(node->val);
    nodeCopy[node] = copy;
    
    copy->next = solve(node->next, nodeCopy);
    copy->random = solve(node->random, nodeCopy);
    
    return copy;
  }
};