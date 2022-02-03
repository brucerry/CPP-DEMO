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
Node* insertNode(Node* head, std::string value, int idx) {
  if (head == nullptr) return nullptr;
  
  if (idx == 0) {
    Node* node = new Node(value);
    node->next = head;
    return node;
  }
  
  if (idx == 1) {
    Node* node = new Node(value);
    Node* next = head->next;
    head->next = node;
    node->next = next;
  } else {
    insertNode(head->next, value, idx - 1);
  }
  
  return head;
}




// iterative
Node* _insertNode(Node* head, std::string value, int idx) {
  Node* node = new Node(value);
  if (idx == 0) {
    node->next = head;
    return node;
  }
  
  Node* prev = nullptr;
  Node* current = head;
  int count = 0;
  
  while (count < idx) {
    prev = current;
    current = current->next;
    count++;
  }
  
  prev->next = node;
  node->next = current;
  
  return head;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}