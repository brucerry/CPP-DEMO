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
    unordered_map<Node*, Node*> nodeToCopy { // originalNode, copyNode
      { nullptr, nullptr }
    };
    
    Node* cur = head;
    
    while (cur) {
      nodeToCopy[cur] = new Node(cur->val);
      cur = cur->next;
    }
    
    cur = head;
    
    while (cur) {
      Node* copy = nodeToCopy[cur];
      copy->next = nodeToCopy[cur->next];
      copy->random = nodeToCopy[cur->random];

      cur = cur->next;
    }
    
    return nodeToCopy[head];
  }
};

// n = len of list
// time: O(n)
// space: O(n)
class Recursive {
public:
  Node* copyRandomList(Node* head) {    
    unordered_map<Node*, Node*> nodeToCopy {
      { nullptr, nullptr }
    };
    
    return solve(head, nodeToCopy);
  }
  
private:
  Node* solve(Node* node, unordered_map<Node*, Node*>& nodeToCopy) {
    if (nodeToCopy.count(node))
      return nodeToCopy[node];
    
    Node* copy = new Node(node->val);
    
    nodeToCopy[node] = copy;
    
    copy->next = solve(node->next, nodeToCopy);
    copy->random = solve(node->random, nodeToCopy);
    
    return copy;
  }
};