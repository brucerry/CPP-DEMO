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
Node* zipperLists(Node* head1, Node* head2) {
  if (head1 == nullptr) return head2;
  if (head2 == nullptr) return head1;
  
  head2->next = zipperLists(head1->next, head2->next);
  head1->next = head2;
  
  return head1;
}




// iterative
Node* _zipperLists(Node* head1, Node* head2) {
  Node* root = head1;
  while (head1 != nullptr && head2 != nullptr) {
    Node* next1 = head1->next;
    Node* next2 = head2->next;
    head1->next = head2;
    if (next1 != nullptr) head2->next = next1;
    
    head1 = next1;
    head2 = next2;
  }
  return root;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}