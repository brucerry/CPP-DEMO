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

// recursive
Node* reverseList(Node* head, Node* prev) {
  if (head == nullptr) return prev;
  
  Node* newHead = reverseList(head->next, head);
  head->next = prev;
  return newHead;
}

Node* reverseList(Node* head) {
  return reverseList(head, nullptr);
}


// iterative
Node* _reverseList(Node* head) {
  Node* prev = nullptr;
  while (head != nullptr) {
    Node* next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}