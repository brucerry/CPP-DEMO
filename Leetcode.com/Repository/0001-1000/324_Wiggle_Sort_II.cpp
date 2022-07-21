// https://leetcode.com/problems/wiggle-sort-ii/

#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)%2BO(1)-after-median-Virtual-Indexing
// time: O(n) on average
// space: O(1) after finding median
class LeetcodeDiscussSolution {
public:
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    
    // Find a median.
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;
    
    // Index-rewiring.
    #define A(i) nums[(1+2*(i)) % (n|1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
      if (A(j) > mid)
        swap(A(i++), A(j++));
      else if (A(j) < mid)
        swap(A(j), A(k--));
      else
        j++;
    }
  }
};

// time: O(n * log(n))
// space: O(n)
class Sorting {
public:
  void wiggleSort(vector<int>& nums) {
    vector<int> sorted (nums);
    sort(sorted.begin(), sorted.end());
    
    for (int i = nums.size() - 1, j = 0, k = i / 2 + 1; i >= 0; i--)
      nums[i] = sorted[ i & 1 ? k++ : j++ ];
  }
};