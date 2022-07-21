// https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/

#include <vector>
#include <bitset>
using namespace std;

// time: O(n^3)
// space: O(n^2)
class AdjacencyMatrix {
public:
  int minTrioDegree(int n, vector<vector<int>>& edges) {
    vector<vector<char>> connected (n + 1, vector<char>(n + 1));
    vector<int> degrees (n + 1);
    for (const auto& edge : edges) {
      int node1 = edge[0];
      int node2 = edge[1];
      connected[node1][node2] = connected[node2][node1] = 1;
      degrees[node1]++;
      degrees[node2]++;
    }
    
    int degree = INT_MAX;
    for (int node1 = 1; node1 <= n - 2; node1++) {
      for (int node2 = node1 + 1; node2 <= n - 1; node2++) {
        if (connected[node1][node2]) {
          for (int node3 = node2 + 1; node3 <= n; node3++) {
            if (connected[node1][node3] and connected[node2][node3]) {
              degree = min(degree, degrees[node1] + degrees[node2] + degrees[node3] - 6);
            }
          }
        }
      }
    }
    
    return degree == INT_MAX ? -1 : degree;
  }
};

// slower than O(n^3) solution because 400bits each is really huge to be handled (?)
// time: O(n * e)
// space: O(n)
class Bitset {
public:
  int minTrioDegree(int n, vector<vector<int>>& edges) {
    vector<bitset<400>> connected (n + 1);
    vector<int> degrees (n + 1);
    for (const auto& edge : edges) {
      int node1 = edge[0];
      int node2 = edge[1];
      connected[node1].set(node2 - 1);
      connected[node2].set(node1 - 1);
      degrees[node1]++;
      degrees[node2]++;
    }
    
    int degree = INT_MAX;
    for (const auto& edge : edges) {
      int node1 = edge[0];
      int node2 = edge[1];
      bitset<400> common = connected[node1] & connected[node2];
      for (int node3 = 1; node3 <= n; node3++) {
        if (common[node3 - 1])
          degree = min(degree, degrees[node1] + degrees[node2] + degrees[node3] - 6);
      }
    }
    
    return degree == INT_MAX ? -1 : degree;
  }
};

// time: O(n * e)
// space: O(n^2)
class AdjacencyMatrixBitsetConcept {
public:
  int minTrioDegree(int n, vector<vector<int>>& edges) {
    vector<vector<char>> connected (n + 1, vector<char>(n + 1));
    vector<int> degrees (n + 1);
    for (const auto& edge : edges) {
      int node1 = edge[0];
      int node2 = edge[1];
      connected[node1][node2] = connected[node2][node1] = 1;
      degrees[node1]++;
      degrees[node2]++;
    }
    
    int degree = INT_MAX;
    for (const auto& edge : edges) {
      int node1 = edge[0];
      int node2 = edge[1];
      if (connected[node1][node2]) {
        for (int node3 = 1; node3 <= n; node3++) {
          if (connected[node1][node3] and connected[node2][node3]) {
            degree = min(degree, degrees[node1] + degrees[node2] + degrees[node3] - 6);
          }
        }
      }
    }
    
    return degree == INT_MAX ? -1 : degree;
  }
};