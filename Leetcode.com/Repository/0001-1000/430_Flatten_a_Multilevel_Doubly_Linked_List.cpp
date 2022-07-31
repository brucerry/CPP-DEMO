// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/


class Node {
public:
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

// time: O(n)
// space: O(1)
class Iterative {
public:
  Node* flatten(Node* head) {
    for (Node* cur = head; cur; cur = cur->next) {
      if (cur->child) {
        Node* tail = cur->child;
        while (tail->next)
          tail = tail->next;
        if (cur->next)
          cur->next->prev = tail;
        tail->next = cur->next;
        cur->next = cur->child;
        cur->child->prev = cur;
        cur->child = nullptr;
      }
    }
    return head;
  }
};

// time: O(n)
// space: O(n)
class Recursive {
public:
  Node* flatten(Node* head) {
    getTail(head);
    return head;
  }
  
private:
  Node* getTail(Node* node) {
    if (!node or (!node->next and !node->child))
      return node;
    
    if (node->child) {
      Node* childHead = node->child, *childTail = getTail(childHead);
      node->child = nullptr;
      Node* next = node->next;
      if (next)
        next->prev = childTail;
      childTail->next = next;
      node->next = childHead;
      childHead->prev = node;
    }
    
    return getTail(node->next);
  }
};