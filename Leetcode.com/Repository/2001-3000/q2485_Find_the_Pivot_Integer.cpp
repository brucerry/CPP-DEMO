// https://leetcode.com/problems/find-the-pivot-integer/

// time: O(1)
// space: O(1)

class Math {
public:
  int pivotInteger(int n) {
    int sum = (n + 1) * n / 2, x = sqrt(sum);
    return x * x == sum ? x : -1;
  }
};

// time: O(n)
// space: O(1)

class RunningSum {
public:
  int pivotInteger(int n) {
    int sum = (n + 1) * n / 2;
    int leftsum = 0, rightsum = sum;
    for (int x = 1; x <= n; x++) {
      leftsum += x;
      if (leftsum == rightsum)
        return x;
      rightsum -= x;
    }
    return -1;
  }
};

class SumEquation {
public:
  int pivotInteger(int n) {
    for (int x = 1; x <= n; x++) {
      int leftsum = (1 + x) * x / 2;
      int rightsum = (x + n) * (n - x + 1) / 2;
      if (leftsum == rightsum)
        return x;
    }
    return -1;
  }
};