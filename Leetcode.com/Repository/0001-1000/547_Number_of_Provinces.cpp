// https://leetcode.com/problems/number-of-provinces/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    
    vector<int> parents (n);
    for (int node = 0; node < n; node++)
      parents[node] = node;
    
    int province = n;
    for (int node1 = 0; node1 < n; node1++) {
      for (int node2 = node1 + 1; node2 < n; node2++) {
        if (isConnected[node1][node2]) {
          province -= unionNodes(parents, node1, node2);
        }
      }
    }
    
    return province;
  }
  
private:
  int unionNodes(vector<int>& parents, int node1, int node2) {
    int parent1 = findParent(parents, node1);
    int parent2 = findParent(parents, node2);
    
    if (parent1 == parent2)
      return 0;
    
    parents[parent1] = parent2;
    return 1;
  }
  
  int findParent(vector<int>& parents, int node) {
    while (node != parents[node]) {
      parents[node] = parents[parents[node]];
      node = parents[node];
    }
    return node;
  }
};