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



bool linkedListFind(Node* head, std::string target) {
  if (head == nullptr) return false;
  if (head->val == target) return true;
  return linkedListFind(head->next, target);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}