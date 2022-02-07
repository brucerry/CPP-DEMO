#include <vector>

class Node {
  public:
    int val;
    Node *next;

    Node(int initialVal)
    {
      val = initialVal;
      next = nullptr;
    }
};


// recursive
Node *addLists(Node *head1, Node *head2, int carry) {
  if (head1 == nullptr && head2 == nullptr && carry == 0) return nullptr;
    
  int val1 = head1 == nullptr ? 0 : head1->val;
  int val2 = head2 == nullptr ? 0 : head2->val;
  int ans = val1 + val2 + carry;
  int digit = ans % 10;
  carry = ans / 10;
  
  Node* node = new Node(digit);
  if (head1 != nullptr) head1 = head1->next;
  if (head2 != nullptr) head2 = head2->next;
  node->next = addLists(head1, head2, carry);
  
  return node;
}

Node *addLists(Node *head1, Node *head2) {
  return addLists(head1, head2, 0);
}




// iterative
Node *_addLists(Node *head1, Node *head2) {
  Node* dummy = new Node(0);
  Node* tail = dummy;
  int carry = 0;
  
  while (head1 != nullptr || head2 != nullptr || carry) {
    int val1 = head1 == nullptr ? 0 : head1->val;
    int val2 = head2 == nullptr ? 0 : head2->val;
    int ans = val1 + val2 + carry;
    int digit = ans % 10;
    carry = ans / 10;
    
    Node* node = new Node(digit);
    tail->next = node;
    tail = tail->next;
    
    if (head1 != nullptr) head1 = head1->next;
    if (head2 != nullptr) head2 = head2->next;
  }
  
  return dummy->next;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}