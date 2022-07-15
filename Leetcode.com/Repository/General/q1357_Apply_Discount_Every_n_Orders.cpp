// https://leetcode.com/problems/apply-discount-every-n-orders/

#include <vector>
#include <array>
using namespace std;

// time: O(n)
// space: O(n)

class Cashier {
public:
  Cashier(int n, int discount, vector<int>& products, vector<int>& prices)
    : customerCount(0), nth(n), discount((100 - discount) / 100.0) {
    
    for (int i = 0; i < products.size(); i++) {
      int id = products[i], price = prices[i];
      productPrices[id] = price;
    }
  }
  
  double getBill(vector<int> product, vector<int> amount) {
    double bill = 0;
    for (int i = 0; i < product.size(); i++) {
      int id = product[i], price = productPrices[id], qty = amount[i];
      bill += price * qty;
    }
    return bill * (++customerCount % nth ? 1 : discount);
  }
  
private:
  int customerCount, nth;
  double discount;
  array<int, 201> productPrices { 0 };
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */