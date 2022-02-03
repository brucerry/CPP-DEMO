#include <vector>
#include <string>
using namespace std;

class Node {
  public:
    std::string val;
    Node* next;

    Node(std::string initialVal) {
      val = initialVal;
      next = nullptr;
    }
};


void linkedListValues(Node* head, vector<string>& values) {
  if (head == nullptr) return;
  values.push_back(head->val);
  linkedListValues(head->next, values);
}


std::vector<std::string> linkedListValues(Node* head) {
  vector<string> values;
  linkedListValues(head, values);
  return values;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}