// https://leetcode.com/problems/product-of-array-except-self/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class SpaceOptimized {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> result (n);
    int prefix = 1, postfix = 1;
    
    for (int i = 0; i < n; i++) {
      result[i] = prefix;
      prefix *= nums[i];
    }
    
    for (int i = n - 1; i >= 0; i--) {
      result[i] *= postfix;
      postfix *= nums[i];
    }
    
    return result;
  }
};

// time: O(n)
// space: O(n)
class PrefixPostfixArray {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> prefix (n), postfix (n);
    prefix[0] = postfix.back() = 1;
    
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i-1] * nums[i-1];
    }
    
    for (int i = n - 2; i >= 0; i--) {
      postfix[i] = postfix[i+1] * nums[i+1];
    }
    
    for (int i = 0; i < n; i++) {
      nums[i] = prefix[i] * postfix[i];
    }
    
    return nums;
  }
};