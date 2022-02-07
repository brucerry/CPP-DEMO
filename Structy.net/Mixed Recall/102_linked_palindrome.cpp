#include <vector>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int initialVal) {
      val = initialVal;
      next = nullptr;
    }
};


bool linkedPalindrome(Node* head) {
  vector<int> nums;
  
  while (head != nullptr) {
    nums.push_back(head->val);
    head = head->next;
  }
  
  for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
    if (nums[i] != nums[j]) return false;
  }
  
  return true;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}