// https://leetcode.com/problems/online-stock-span/

#include <stack>
using namespace std;

class StockSpanner {
public:
  StockSpanner() {
    
  }
  
  int next(int price) {
    int span = 1;
    while (stocks.size() and stocks.top().first <= price) {
      span += stocks.top().second;
      stocks.pop();
    }
    stocks.emplace(price, span);
    return span;
  }
  
private:
  stack<pair<int, int>> stocks; // price, span
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */