// https://leetcode.com/problems/design-an-atm-machine/

#include <vector>
using namespace std;

// time: O(1)
// space: O(1)

class ATM {
public:
  ATM() {

  }

  void deposit(vector<int> banknotesCount) {
    for (int i = 0; i < 5; i++) {
      counts[i] += banknotesCount[i];
    }
  }

  vector<int> withdraw(int amount) {
    vector<int> result (5);
    for (int i = 4; i >= 0; i--) {
      int exhaust = min(amount / banknotes[i], counts[i]);
      result[i] = exhaust;
      amount -= exhaust * banknotes[i];
    }
    if (amount)
      return { -1 };
    for (int i = 0; i < 5; i++) {
      counts[i] -= result[i];
    }
    return result;
  }
  
private:
  vector<long> banknotes { 20, 50, 100, 200, 500 }, counts { 0, 0, 0, 0, 0 };
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */