// https://leetcode.com/problems/k-th-symbol-in-grammar/

// time: O(log(k))
// space: O(log(k))

class Solution {
public:
  int kthGrammar(int n, int k) {
    if (k == 1)
      return 0;
    
    int half = (1 << (n - 1)) / 2;
    if (k <= half)
      return kthGrammar(n - 1, k);
    return !kthGrammar(n - 1, k - half);
  }
};