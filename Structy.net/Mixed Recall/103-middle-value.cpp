#include <string>
#include <vector>
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


// time: O(n)
// space: O(1)
std::string middleValue(Node* head) {
  Node* fast = head;
  Node* slow = head;
  
  while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }
  
  return slow->val;
}



// time: O(n)
// space: O(n)
std::string _middleValue(Node* head) {
  vector<string> values;
  
  while (head != nullptr) {
    values.push_back(head->val);
    head = head->next;
  }
  
  return values[values.size() / 2];
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}