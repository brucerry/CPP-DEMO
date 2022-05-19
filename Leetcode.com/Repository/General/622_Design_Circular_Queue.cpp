// https://leetcode.com/problems/design-circular-queue/

// Double Linked List
// time: O(1)
// space: O(k)

class MyCircularQueue {
public:
  MyCircularQueue(int k)
    : m_Size(0), m_MaxSize(k), m_Front(new Node(0, nullptr, m_Rear)), m_Rear(new Node(0, m_Front, nullptr)) {}
    
  bool enQueue(int value) {
    if (isFull())
      return false;
    
    Node* newNode = new Node(value, m_Rear->front, m_Rear);
    newNode->front->back = m_Rear->front = newNode;
    
    m_Size++;
    return true;
  }
    
  bool deQueue() {
    if (isEmpty())
      return false;
    
    m_Front->back = m_Front->back->back;
    m_Front->back->front = m_Front;
    
    m_Size--;
    return true;
  }
    
  int Front() {
    return isEmpty() ? -1 : m_Front->back->val;
  }
    
  int Rear() {
    return isEmpty() ? -1 : m_Rear->front->val;
  }
    
  bool isEmpty() {
    return m_Size == 0;
  }
    
  bool isFull() {
    return m_Size == m_MaxSize;
  }
  
private:
  struct Node {
    int val;
    Node* front, *back;
    
    Node(int _val, Node* _front, Node* _back) : val(_val), front(_front), back(_back) {};
  };
  
  Node* m_Front, *m_Rear;
  int m_Size, m_MaxSize;
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