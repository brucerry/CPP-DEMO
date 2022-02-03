class Node {
  public:
    int val;
    Node* next;

    Node(int initialVal) {
      val = initialVal;
      next = nullptr;
    }
};


// recursive
Node* mergeLists(Node* head1, Node* head2) {
  if (head1 == nullptr) return head2;
  if (head2 == nullptr) return head1;
  
  if (head1->val < head2->val) {
    head1->next = mergeLists(head1->next, head2);
    return head1;
  } else {
    head2->next = mergeLists(head1, head2->next);
    return head2;
  }
}


// iterative
Node* _mergeLists(Node* head1, Node* head2) {
  Node dummy(0);
  Node* tail = &dummy;
  
  while (head1 != nullptr && head2 != nullptr) {
    if (head1->val < head2->val) {
      tail->next = head1;
      head1 = head1->next;
    } else {
      tail->next = head2;
      head2 = head2->next;
    }
    tail = tail->next;
  }
  
  if (head1 != nullptr) {
    tail->next = head1;
  }
  if (head2 != nullptr) {
    tail->next = head2;
  }
  
  return dummy.next;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}