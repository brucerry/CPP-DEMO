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


std::string getNodeValue(Node* head, int idx, int i) {
  if (head == nullptr) return "";
  if (i == idx) return head->val;
  return getNodeValue(head->next, idx, i+1);
}

std::string getNodeValue(Node* head, int idx) {
  return getNodeValue(head, idx, 0);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}