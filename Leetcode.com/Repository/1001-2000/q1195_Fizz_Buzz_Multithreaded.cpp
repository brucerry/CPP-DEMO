// https://leetcode.com/problems/fizz-buzz-multithreaded/

#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std;

// time: O(n) in total
// space: O(1)

class FizzBuzz {
private:
  int n;
  int counter;
  mutex mtx;
  condition_variable cv;

public:
  FizzBuzz(int n) {
    this->n = n;
    this->counter = 1;
  }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz) {
    unique_lock<mutex> lck (mtx);
    while (true) {
      while (counter <= n and !(counter % 3 == 0 and counter % 5))
        cv.wait(lck);
      if (counter > n)
        return;
      printFizz();
      counter++;
      cv.notify_all();
    }
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz) {
    unique_lock<mutex> lck (mtx);
    while (true) {
      while (counter <= n and !(counter % 3 and counter % 5 == 0))
        cv.wait(lck);
      if (counter > n)
        return;
      printBuzz();
      counter++;
      cv.notify_all();
    }
  }

  // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
    unique_lock<mutex> lck (mtx);
    while (true) {
      while (counter <= n and !(counter % 15 == 0))
        cv.wait(lck);
      if (counter > n)
        return;
      printFizzBuzz();
      counter++;
      cv.notify_all();
    }
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber) {
    unique_lock<mutex> lck (mtx);
    while (true) {
      while (counter <= n and !(counter % 3 and counter % 5))
        cv.wait(lck);
      if (counter > n)
        return;
      printNumber(counter);
      counter++;
      cv.notify_all();
    }
  }
};