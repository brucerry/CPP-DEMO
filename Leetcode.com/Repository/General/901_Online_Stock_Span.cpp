// https://leetcode.com/problems/online-stock-span/

#include <stack>
using namespace std;

// time: O(n)
// space: O(n)

class StockSpanner {
public:
  StockSpanner() {
    
  }
  
  int next(int price) {
    int span = 1;
    while (m_Stock.size() and m_Stock.top().first <= price) {
      span += m_Stock.top().second;
      m_Stock.pop();
    }
    m_Stock.emplace(price, span);
    return span;
  }
  
private:
  stack<pair<int, int>> m_Stock; // price, span
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */