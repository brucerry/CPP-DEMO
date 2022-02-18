// https://leetcode.com/problems/online-stock-span/

#include <stack>
using namespace std;

class StockSpanner {
private:
  stack<pair<int, int>> stack;

public:
  StockSpanner() {
    
  }
    
  int next(int price) {
    int span = 1;
    while (stack.size()) {
      auto [ topPrice, topSpan ] = stack.top();
      if (price >= topPrice) {
        span += topSpan;
        stack.pop();
      } else {
        break;
      }
    }
    stack.push({price, span});
    return span;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */