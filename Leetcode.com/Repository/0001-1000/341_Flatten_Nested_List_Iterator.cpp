// https://leetcode.com/problems/flatten-nested-list-iterator/

#include <vector>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// time: O(n) for constructor, O(1) for next() and hasNext()
// space: O(n)

class NestedIterator {
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    FlattenList(nestedList, list);
    it = list.begin();
  }
  
  int next() {
    return *it++;
  }
  
  bool hasNext() {
    return it != list.end();
  }
  
private:
  vector<int> list;
  vector<int>::iterator it;
  
  void FlattenList(const vector<NestedInteger> const &nestedList, vector<int>& list) {
    for (const NestedInteger& nl : nestedList) {
      if (nl.isInteger())
        list.emplace_back(nl.getInteger());
      else
        FlattenList(nl.getList(), list);
    }
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */