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
bool isUnivalueList(Node* head, Node* current) {
  if (current == nullptr) return true;
  
  if (head->val != current->val) return false;
  
  return isUnivalueList(head, current->next);
}

bool isUnivalueList(Node* head) {
  return isUnivalueList(head, head);
}



// iterative
bool _isUnivalueList(Node* head) {
  int value = head->val;
  head = head->next;
  while (head != nullptr) {
    if (value != head->val) return false;
    head = head->next;
  }
  return true;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}