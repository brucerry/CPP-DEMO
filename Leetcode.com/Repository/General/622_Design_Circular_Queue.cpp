// https://leetcode.com/problems/design-circular-queue/

// Double Linked List
// time: O(1)
// space: O(k)

class MyCircularQueue {
public:
  MyCircularQueue(int k) : cap(k), size(0), head(new Node(0)), tail(new Node(0)) {
    head->right = tail;
    tail->left = head;
  }
  
  bool enQueue(int value) {
    if (isFull())
      return false;
    Node* node = new Node(value);
    node->left = tail->left;
    node->right = tail;
    tail->left = tail->left->right = node;
    size++;
    return true;
  }
  
  bool deQueue() {
    if (isEmpty())
      return false;
    Node* node = head->right;
    head->right = node->right;
    node->right->left = head;
    delete node;
    size--;
    return true;
  }
  
  int Front() {
    return isEmpty() ? -1 : head->right->val;
  }
  
  int Rear() {
    return isEmpty() ? -1 : tail->left->val;
  }
  
  bool isEmpty() {
    return size == 0;
  }
  
  bool isFull() {
    return size == cap;
  }
  
private:
  struct Node {
    int val;
    Node* left, *right;
    
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
  };
  
  Node* head, *tail;
  int cap, size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */