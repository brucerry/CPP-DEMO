#include <string>

class Node {
  public:
    std::string val;
    Node* next;

    Node(std::string initialVal) {
      val = initialVal;
      next = nullptr;
    }
};



// iterative
Node* removeNode(Node* head, std::string targetVal) {
  Node* prev = nullptr;
  Node* cur = head;
  
  while (cur != nullptr) {
    if (cur->val == targetVal) {
      if (prev == nullptr) {
        return cur->next;
      }
      prev->next = cur->next;
      break;
    }
    prev = cur;
    cur = cur->next;
  }
  
  return head;
}



// recursive
Node* _removeNode(Node* head, std::string targetVal) {
  if (head == nullptr) return nullptr;
  
  if (head->val == targetVal) return head->next;
  
  head->next = removeNode(head->next, targetVal);
  
  return head;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}