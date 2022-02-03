#include <string>
#include <vector>


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
Node* createLinkedList(std::vector<std::string> values, int idx) {
  if (idx == values.size()) return nullptr;
  
  Node* node = new Node(values[idx]);
  node->next = createLinkedList(values, idx+1);
  
  return node;
}

Node* createLinkedList(std::vector<std::string> values) {
  return createLinkedList(values, 0);
}



// iterative
Node* _createLinkedList(std::vector<std::string> values) {
  Node dummy("");
  Node* current = &dummy;
  
  for (auto val : values) {
    Node* node = new Node(val);
    current->next = node;
    current = current->next;
  }
  
  return dummy.next;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}