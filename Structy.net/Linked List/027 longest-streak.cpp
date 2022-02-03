class Node {
  public:
    int val;
    Node* next;

    Node(int initialVal) {
      val = initialVal;
      next = nullptr;
    }
};


// iterative
int longestStreak(Node* head) {
  int max = 0;
  int count = 0;
  int prevVal;
  
  while (head != nullptr) {
    if (count == 0) {
      max = count = 1;
      prevVal = head->val;
    } else {
      if (head->val == prevVal) {
        count++;
      } else {
        count = 1;
        prevVal = head->val;
      }
    }
    head = head->next;
    if (max < count) max = count;
  }
  
  return max;
}



// recursive
int _longestStreak(Node* prev, Node* current, int count, int max) {
  if (current == nullptr) return max;
  
  if (prev->val == current->val) count++;
  else count = 1;
    
  if (count > max) max = count;
  
  return _longestStreak(current, current->next, count, max);
}

int _longestStreak(Node* head) {
  return _longestStreak(head, head, 0, 0);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}